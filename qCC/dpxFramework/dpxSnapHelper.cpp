
//by duans
#include "dpxSnapHelper.h"

dpxSnapHelper* dpxSnapHelper::Instance()
{
	static dpxSnapHelper instance;
	return &instance;
}

dpxSnapHelper::dpxSnapHelper()
{
	MainWindow* pMainWindow = MainWindow::TheInstance();
	if(pMainWindow==nullptr || pMainWindow==0)
	{
		ccLog::Warning("no current Main Window");
		return;
	}
	m_pCurActiveWindow = pMainWindow->getActiveGLWindow();
	if(m_pCurActiveWindow!=nullptr)
	{
		m_pShowRootObject = new ccHObject("RootShow");
		m_pCurActiveWindow->addToOwnDB(m_pShowRootObject);
	}
}

void dpxSnapHelper::ClearShowObject()
{
	if(m_pShowRootObject==nullptr || m_pCurActiveWindow==nullptr)
		return;

	m_pShowRootObject->removeAllChildren();
}

void dpxSnapHelper::AddTempShowObject(ccHObject* pTempShowObj,bool bOnlyOne /*= true*/)
{
	if(pTempShowObj==nullptr || m_pShowRootObject==nullptr)
		return;
	if(bOnlyOne)
	{
		m_pShowRootObject->removeAllChildren();
	}

	pTempShowObj->setDisplay(m_pCurActiveWindow);
	pTempShowObj->setEnabled(true);
	pTempShowObj->setVisible(true);
	m_pShowRootObject->addChild(pTempShowObj);
}

//获取树状图里所有的线
bool dpxSnapHelper::FindAllObjs(ccHObject::Container& vecHObjs,CC_CLASS_ENUM filter/*= CC_TYPES::POLY_LINE*/)
{
	MainWindow* pMainWindow = MainWindow::TheInstance();
	ccDBRoot* pDBRootModel  = pMainWindow->GetDBRoot();
	if(pDBRootModel==nullptr)
		return false;
	ccHObject*pHRoot = pDBRootModel->getRootEntity();
	if(pHRoot==nullptr)
		return false;

	vecHObjs.clear();
	pHRoot->filterChildren(vecHObjs,true,CC_TYPES::POLY_LINE);

	return !vecHObjs.empty();
}

bool dpxSnapHelper::isBoxIntersectWithRay(ccBBox box,Ray<float> ray)
{
	if(!box.isValid())
		return false;

	CCVector3 minconner = box.minCorner();
	CCVector3 maxconner = box.maxCorner();

	AABB<float> aabbBox(minconner,maxconner);
	return aabbBox.intersects(ray);
}

//投影至平面，供屏幕捕捉使用
bool dpxSnapHelper::ProjectLinesTo2D(ccHObject::Container& vec3DLines,ccHObject::Container& vec2DLines)
{
	if(m_pCurActiveWindow==nullptr || m_pCurActiveWindow==0)
		return false;

	ccGLCameraParameters camera;
	m_pCurActiveWindow->getGLCameraParameters(camera);

	for(int i =0;i<vec3DLines.size();i++)
	{
		ccHObject* pHObj = vec3DLines[i];
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pHObj);
		if(pLine==nullptr)
			continue;
		ccPointCloud* polyVertices = new ccPointCloud("Vertices");
		ccPolyline* poly2D = new ccPolyline(polyVertices);
		polyVertices->setEnabled(false);
		poly2D->set2DMode(true);
		poly2D->addChild(polyVertices);
		poly2D->setWidth(1);

		for(int i=0;i<pLine->size();i++)
		{
			const CCVector3* P3D = pLine->getPoint(i);
			CCVector3d Pose2D(-1,-1,-1);
			camera.project(*P3D,Pose2D);

			float x = static_cast<PointCoordinateType>(Pose2D.x);
			float y = static_cast<PointCoordinateType>(Pose2D.y);

			//CCVector3 P2D(x-camera.viewport[2]/2,y-camera.viewport[3]/2,0);
			CCVector3 P2D(x,y,0);
			polyVertices->reserve(polyVertices->size()+1);
			poly2D->reserve(polyVertices->size()+1);

			polyVertices->addPoint(P2D);
			poly2D->addPointIndex(polyVertices->size()-1);
		}

		vec2DLines.push_back(poly2D);
	}
	return true;
}


