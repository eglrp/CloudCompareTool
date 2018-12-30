
#include "dpxAutoCreateMapSetting.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/normal_3d.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/common/transforms.h>

//qCC_db
#include <ccLog.h>
#include <CCGeom.h>
#include <ccPolyline.h>
#include <ccHObjectCaster.h>
#include <ccGenericPointCloud.h>
#include <ccPointCloud.h>
#include <GenericIndexedCloudPersist.h>
#include <ccPlane.h>
#include <ccCylinder.h>
#include <QDateTime>
#include <dpxGeoEngine.h>
#include "mainwindow.h"
dpxAutoCreateMapSetting:: dpxAutoCreateMapSetting(ccGLWindow* associatedWin,QWidget* parent/*=0*/)
	: dpxVisibleSetting(associatedWin,parent)
{
	m_pGLWindow = nullptr;
}

dpxAutoCreateMapSetting::~dpxAutoCreateMapSetting()
{
}

void dpxAutoCreateMapSetting::accept()
{
	dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
	if(pMap==nullptr)
		return;
	// Pole
	dpxLayer* pPoleLyr = pMap->getPoleLyr();
	if(pPoleLyr==nullptr)
		return;

	ccHObject* pLRootObj = pPoleLyr->getRootData();
	if(pLRootObj==nullptr)
		return;

	ccGenericGLDisplay* pDisplay = nullptr;

	VSparam param = getParams();
	QString strScalar = param.m_strScalar;
	ccLog::Warning(strScalar);

	pcl::PointCloud<pcl::PointXYZ>::Ptr pPcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	//for each selected entity
	for (QSet<ccHObject*>::const_iterator p = m_toSetVisible.constBegin(); p != m_toSetVisible.constEnd(); ++p)
	{
		ccGenericPointCloud* cloud = ccHObjectCaster::ToGenericPointCloud(*p);
		assert(cloud);

		ccPointCloud* ccloud = ccHObjectCaster::ToPointCloud(*p);
		if(ccloud==nullptr)
			continue;

		pDisplay = ccloud->getDisplay();

		int nScalarCount = ccloud->getNumberOfScalarFields();
		int nScalarIndex = ccloud->getScalarFieldIndexByName(strScalar.toLatin1().data());
		ccLog::Warning("nScalarCount:" + QString::number(nScalarCount) + "nScalarIndex:"+QString::number(nScalarIndex));

		unsigned cloudSize = cloud->size();
		for (int i = 0; i < static_cast<int>(cloudSize); ++i)
		{
			if(nScalarIndex>-1 && nScalarIndex < nScalarCount)
			{
				ScalarType dValue  = ccloud->getPointScalarValueV2(nScalarIndex,i);
				if( IsInRange(param.m_vecScalar,dValue) ) //如果是筛选的点
				{
					//存储该点
					const CCVector3* p3DPoint = cloud->getPoint(i);
					double  dX =  p3DPoint->x;
					double  dY =  p3DPoint->y;
					double  dZ =  p3DPoint->z;

					pcl::PointXYZ pclPt(dX,dY,dZ);
					pPcl_cloud->push_back(pclPt);
				}
			}
		}
	}
	//处理out_cloud
	pPcl_cloud->size();
//
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
    pcl::ExtractIndices<pcl::PointXYZ> extract;      //点提取对象
    pcl::PointCloud<pcl::Normal>::Ptr ground_normals (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::Normal>::Ptr pole_normals (new pcl::PointCloud<pcl::Normal>);
    // 过滤后的点云进行法线估计，为后续进行基于法线的分割准备数据

    tree->setInputCloud (pPcl_cloud);

    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;   //欧式聚类对象
    ec.setClusterTolerance (2);                   // 设置近邻搜索的搜索半径为2cm
    ec.setMinClusterSize (20);                 //设置一个聚类需要的最少的点数目为100
    ec.setMaxClusterSize (25000);               //设置一个聚类需要的最大点数目为25000
    ec.setSearchMethod (tree);                    //设置点云的搜索机制
    ec.setInputCloud (pPcl_cloud);
    ec.extract (cluster_indices);           //从点云中提取聚类，并将点云索引保存在cluster_indices中


    //extract each pole after EuclideanCluster
    for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr pole_cluster (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr part (new pcl::PointCloud<pcl::PointXYZ>);

        double min_z = 999999;
        double max_z = -999999;
        for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
        {
            pole_cluster->points.push_back (pPcl_cloud->points[*pit]); //*
            if(pPcl_cloud->points[*pit].z < min_z)
                min_z = pPcl_cloud->points[*pit].z;
        }
        for(int i = 0; i < pole_cluster->points.size(); i++)
        {
            if(pole_cluster->points[i].z - min_z < 3)
                part->points.push_back(pole_cluster->points[i]);
        }
        if(part->points.size() < 10) continue;
        pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;  //法线估计对象
        ne.setSearchMethod (tree);
        ne.setInputCloud (part);
        ne.setKSearch (10);
        ne.compute (*pole_normals);

        pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;  //Fitting Line
        seg.setOptimizeCoefficients(false);
        seg.setModelType(pcl::SACMODEL_LINE );
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setNormalDistanceWeight(0.3);
        seg.setMaxIterations(10000);
        seg.setDistanceThreshold(0.5);
        seg.setRadiusLimits(0, 0.5);
        seg.setInputCloud(part);
        seg.setInputNormals(pole_normals);

        // Obtain the cylinder inliers and coefficients
        pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices), inliers_cylinder (new pcl::PointIndices);
        pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients), coefficients_cylinder (new pcl::ModelCoefficients);

        seg.segment(*inliers_cylinder, *coefficients_cylinder);

        //v.dot(w);//向量点乘
        //v.cross(w);//向量叉乘
        //m是直线外一点，s是直线方向向量，在直线上任找一点M，d=|向量mM×s|/|s|
        Eigen::Vector3d M;
        M <<(double)coefficients_cylinder->values[0],
            (double)coefficients_cylinder->values[1],
            (double)coefficients_cylinder->values[2];
        Eigen::Vector3d s;
        s <<(double)coefficients_cylinder->values[3],
            (double)coefficients_cylinder->values[4],
            (double)coefficients_cylinder->values[5];
        part->clear();
        for(int i = 0; i < pole_cluster->points.size(); i++)
        {
            Eigen::Vector3d m;
            m <<pole_cluster->points[i].x,
                pole_cluster->points[i].y,
                pole_cluster->points[i].z;

            Eigen::Vector3d mM = M - m;

            double distance = (mM.cross(s)).norm()/(s.norm());
            //std::cout << "distance .....       " << distance << std::endl;
            if(distance < 0.25)   //计算
            {
                part->points.push_back(pole_cluster->points[i]);
            }
            if(pole_cluster->points[i].z > max_z)
                max_z = pole_cluster->points[i].z;
        }
        //pcl::NormalEstimation<pcl::PointXYZI, pcl::Normal> ne;  //法线估计对象
        ne.setSearchMethod (tree);
        ne.setInputCloud (part);
        ne.setKSearch (10);
        ne.compute (*pole_normals);

        //pcl::SACSegmentationFromNormals<pcl::PointXYZI, pcl::Normal> seg;
        seg.setOptimizeCoefficients(false);
        seg.setModelType(pcl::SACMODEL_LINE );
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setNormalDistanceWeight(0.1);
        seg.setMaxIterations(10000);
        seg.setDistanceThreshold(0.1);
        seg.setRadiusLimits(0, 0.1);
        seg.setInputCloud(part);
        seg.setInputNormals(pole_normals);

        // Obtain the cylinder inliers and coefficients
        seg.segment(*inliers_cylinder, *coefficients_cylinder);

        //TODO
        if(part->points.size() < 30) continue;
        {
            //点向式：(x-x0）/u =（y-y0）/v=(z-z0) /w ，过点（x0,y0,z0） ,且有方向向量（u,v,w)
            double x0 = (double)coefficients_cylinder->values[0];
            double y0 = (double)coefficients_cylinder->values[1];
            double z0 = (double)coefficients_cylinder->values[2];
            double u = (double)coefficients_cylinder->values[3];
            double v = (double)coefficients_cylinder->values[4];
            double w = (double)coefficients_cylinder->values[5];

            CCVector3 p1;
            p1.x = (min_z-z0)/w*u+x0;
            p1.y = (min_z-z0)/w*v+y0;
            p1.z = min_z;

            CCVector3 p2;
            p2.x = (max_z-z0)/w*u+x0;
            p2.y = (max_z-z0)/w*v+y0;
            p2.z = max_z;

            double pole_height = std::sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
            if(pole_height > 2 && (p1.z-p2.z > 2))
            {
				ccLog::Warning(QString::number(p1.x) + QString::number(p1.y) + QString::number(p1.z));
				ccLog::Warning(QString::number(p2.x) + QString::number(p2.y) + QString::number(p2.z));
            }

            ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCPoleLine  = new ccPolyline(p3DVertices);
			if(!AddPoleInfor(p1,p2,p3DVertices,pCCPoleLine))
				continue;
			pLRootObj->addChild(pCCPoleLine);
        }
    }

	if(m_pGLWindow)
	{
		m_pGLWindow->removeFromOwnDB(pLRootObj);
	}
	if (MainWindow::TheInstance())
	{
		MainWindow::TheInstance()->addToDB(pLRootObj);
	}

	reject();
}


bool  dpxAutoCreateMapSetting::AddPoleInfor(CCVector3 pt1,CCVector3 pt2,ccPointCloud* p3DVertices,ccPolyline* pBorderLine)
{
	if(p3DVertices==nullptr || pBorderLine==nullptr)
		return false;

	double dRadius = 0.2;

	CCVector3 ptFirst = pt1;
	CCVector3 ptSecond = pt2;

	CCVector3 RDisPt;
	getRDisPt(ptFirst,ptSecond,dRadius,RDisPt);

	p3DVertices->reserve(3);
	pBorderLine->reserve(4);
	p3DVertices->addPoint(ptFirst);
	pBorderLine->addPointIndex(0);
	p3DVertices->addPoint(ptSecond);
	pBorderLine->addPointIndex(1);
	p3DVertices->addPoint(RDisPt);
	pBorderLine->addPointIndex(2);
	//缺个点
	double dHeight = sqrt(pow((ptFirst.x-ptSecond.x),2.0) + pow((ptFirst.y-ptSecond.y),2.0) + pow((ptFirst.z-ptSecond.z),2.0));

	//CC system Func
	QString strRelateID = QUuid::createUuid().toString();
	CCVector3 vbefore(0,0,1);
	CCVector3 vafter(ptSecond.x-ptFirst.x, ptSecond.y-ptFirst.y, ptSecond.z-ptFirst.z);
	vafter/=vafter.normd();
	ccGLMatrix transM = ccGLMatrix::FromToRotation(vbefore,vafter);

	CCVector3 vecTrans((ptFirst.x+ptSecond.x)/2,(ptFirst.y+ptSecond.y)/2,(ptFirst.z+ptSecond.z)/2);
	transM.setTranslation(vecTrans);

	QDateTime current_time =QDateTime::currentDateTime();
	QString sCurrentTime =current_time.toString("hh:mm:ss");
	pBorderLine->setName("CylinderLine_"+sCurrentTime);
	pBorderLine->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
	pBorderLine->setMetaData(DPX_RADIUS,QString::number(dRadius));
	pBorderLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Pole); //地物类型

	ccCylinder* pCylinder = new ccCylinder(dRadius,dHeight,&transM,"Cylinder"+sCurrentTime,24);
	pCylinder->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
	pCylinder->setTempColor(ccColor::cyan);
	pBorderLine->addChild(pCylinder);

	return true;
}

void dpxAutoCreateMapSetting::getRDisPt(CCVector3 ptFirst,CCVector3 ptSecond,double dDis,CCVector3& RDisPt)
{
	 if(ptFirst.x==ptSecond.x && ptFirst.y==ptSecond.y)
	 {
		CCVector3 vec(0,0,1);
		RDisPt = ptSecond+dDis*vec;
	 }
	 else if(ptFirst.x==ptSecond.x)
	 {
		RDisPt.y = ptSecond.y;
		RDisPt.z = ptSecond.z;
		RDisPt.z = sqrt(dDis) + ptSecond.y;
	 }
	 else
	 {
		float Xab = ptSecond.x - ptFirst.x;
		float Yab = ptSecond.y - ptFirst.y;
		float Ybc = sqrt( dDis*dDis/(Yab*Yab/(Xab*Xab)+1));

		RDisPt.y = Ybc + ptSecond.y;
		RDisPt.x = -Yab/Xab * Ybc + ptSecond.x;
		RDisPt.z = ptSecond.z;
	 }
	return ;
}
