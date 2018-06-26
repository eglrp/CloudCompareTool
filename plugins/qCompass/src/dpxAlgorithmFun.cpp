//by duans

#include "dpxAlgorithmFun.h"
#include "RayAndBox.h"

//#define DBL_MAX 1.7976931348623158e+30 /* max value */
//const double DBL_MAX = 1.7976931348623158e+308;
//点到三维线的距离
double dpxAlgorithmFun::DistanceOfPointToLine(CCVector3 a, CCVector3 b, CCVector3 s)
{
    double ab = sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0) + pow((a.z - b.z), 2.0));
    double as = sqrt(pow((a.x - s.x), 2.0) + pow((a.y - s.y), 2.0) + pow((a.z - s.z), 2.0));
    double bs = sqrt(pow((s.x - b.x), 2.0) + pow((s.y - b.y), 2.0) + pow((s.z - b.z), 2.0));
    double cos_A = (pow(as,2.0) + pow(ab,2.0) - pow(bs,2.0)) / (2*ab*as);
    double sin_A = sqrt(1 - pow(cos_A, 2.0));

    return as * sin_A;
}


//点S投影到A B直线上的点P
CCVector3 dpxAlgorithmFun::PointProjectionToLine(const CCVector3& PtA, const CCVector3& PtB,const CCVector3& PtS)
{
	// A-B A-C
	CCVector3  AB(PtB.x-PtA.x,PtB.y-PtA.y,PtB.z-PtA.z);
	CCVector3  AS(PtS.x-PtA.x,PtS.y-PtA.y,PtS.z-PtA.z);

	double Dot = AB[0] * AS[0] + AB[1] * AS[1] + AB[2] * AS[2];
	double Before = sqrt(AB[0] * AB[0] + AB[1] * AB[1] + AB[2] *AB[2]);
	double After = sqrt(AS[0] * AS[0] + AS[1] * AS[1] + AS[2] * AS[2]);
	double cosAngle = Dot/Before/After;

	double AS_M = dpxAlgorithmFun::NormalizeValue(AS);
	double AB_M = dpxAlgorithmFun::NormalizeValue(AB);
	double dRadio = AS_M*cosAngle/AB_M;

	//P
	CCVector3 ptP(AB[0]*dRadio+PtA.x,AB[1]*dRadio+PtA.y,AB[2]*dRadio+PtA.z);

	return ptP;
}


//求取旋转向量
CCVector3 dpxAlgorithmFun::rotationAxis(CCVector3 befor, CCVector3 after)
{
    CCVector3 vRotation;
    vRotation[0] = befor[1] * after[2] - befor[2] * after[1];
    vRotation[1] = befor[2] * after[0] - befor[0] * after[2];
    vRotation[2] = befor[0] * after[1] - befor[1] * after[0];

    return vRotation;
}

//求取旋转角度
double dpxAlgorithmFun::rotationAngle(CCVector3 befor, CCVector3 after)
{
    double Dot = befor[0] * after[0] + befor[1] * after[1] + befor[2] * after[2];
	double Before = sqrt(befor[0] * befor[0] + befor[1] * befor[1] + befor[2] *befor[2]);
	double After = sqrt(after[0] * after[0] + after[1] * after[1] + after[2] * after[2]);

    return acos(Dot/Before/After);
}

//求向量的模
double dpxAlgorithmFun::NormalizeValue(CCVector3 v)
{
    return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
}

//向量转成标准向量
CCVector3 dpxAlgorithmFun::NormalVec(CCVector3 vec3)
{
	CCVector3 vResult;
	double length = NormalizeValue(vec3);
	// check length of axis vector
	if (length < 0.0000001)
		return vResult;

	// normalize axis vector
	double f = 1.0 / length;
	vResult.x = f * vec3[0];
	vResult.y = f * vec3[1];
	vResult.z = f * vec3[2];

	return vResult;
}

//平移矩阵
double* dpxAlgorithmFun::translateMatrix(double dX,double dY,double dZ)
{
	double *rotatinMatrix= (double*) malloc(16*sizeof(double));

	rotatinMatrix[0] = 1; 	rotatinMatrix[1] = 0; 	rotatinMatrix[2] = 0; 	rotatinMatrix[3] = 0;
	rotatinMatrix[4] = 0; 	rotatinMatrix[5] = 1; 	rotatinMatrix[6] = 0;	rotatinMatrix[7] = 0;
	rotatinMatrix[8] = 0; 	rotatinMatrix[9] = 0; 	rotatinMatrix[10]= 1;	rotatinMatrix[11] = 0;
	rotatinMatrix[12]=dX; 	rotatinMatrix[13]=dY; 	rotatinMatrix[14]=dZ;	rotatinMatrix[15] = 1;

	return rotatinMatrix;
}

//圆柱直径向量，判断点是否在圆内部
bool dpxAlgorithmFun::inCircle(const CCVector3* segStart, const CCVector3* segEnd, const CCVector3* query)
{
	//calculate vector Query->Start and Query->End
	CCVector3 QS(segStart->x - query->x, segStart->y - query->y, segStart->z - query->z);
	CCVector3 QE(segEnd->x - query->x, segEnd->y - query->y, segEnd->z - query->z);

	//is angle between these vectors obtuce (i.e. QS dot QE) < 0)? If so we are inside a circle between start&end, otherwise we are not
	QS.normalize();
	QE.normalize();

	return QS.dot(QE) < 0;
}

//旋转矩阵
//double* dpxCylinderTool::rotateMatrix(const CCVector3& a_axis,const double& dAngleRad,double dX ,double dY,double dZ)
double* dpxAlgorithmFun::rotateMatrix(const CCVector3& a_axis,const double& dAngleRad)
{
	double *rotatinMatrix= (double *) malloc(16*sizeof(double));

	// normalize axis vector
	double x = a_axis[0];
	double y = a_axis[1];
	double z = a_axis[2];

	// compute rotation matrix
	double c = ::cos(dAngleRad);
	double s = ::sin(dAngleRad);
	double v = 1-c;

//	m(0,0) = x*x*v+c;     m(0,1) = x*y*v-z*s;  m(0,2) = x*z*v+y*s;
//	m(1,0) = x*y*v+z*s;   m(1,1) = y*y*v+c;    m(1,2) = y*z*v-x*s;
//	m(2,0) = x*z*v-y*s;   m(2,1) = y*z*v+x*s;  m(2,2) = z*z*v+c;
	rotatinMatrix[0] = x*x*v+c; 	rotatinMatrix[1] = x*y*v-z*s; 	rotatinMatrix[2] = x*z*v+y*s; 	rotatinMatrix[3] = 0;
	rotatinMatrix[4] = x*y*v+z*s; 	rotatinMatrix[5] = y*y*v+c; 	rotatinMatrix[6] = y*z*v-x*s;	rotatinMatrix[7] = 0;
	rotatinMatrix[8] = x*z*v-y*s; 	rotatinMatrix[9] = y*z*v+x*s; 	rotatinMatrix[10] = z*z*v+c;	rotatinMatrix[11] = 0;
	rotatinMatrix[12] = 0; 			rotatinMatrix[13] = 0; 			rotatinMatrix[14] = 0;			rotatinMatrix[15] = 1;

	return rotatinMatrix;
}

//整合过程
double* dpxAlgorithmFun::rotateMatrix(CCVector3 vbefor,CCVector3 vafter)
{
	vbefor= NormalVec(vbefor);
	vafter = NormalVec(vafter);
	//旋转角度
	double dAngel = rotationAngle(vbefor,vafter);
	//旋转轴
	CCVector3 rotaAxis = rotationAxis(vbefor,vafter);
	//旋转矩阵参数
	double* rotat = rotateMatrix(rotaAxis,dAngel);
	return rotat;
}

bool dpxAlgorithmFun::IsEqual(double d1,double d2)
{
    if (abs(d1 - d2) < 1e-7)
        return true;

    return false;
}

//原理参见博客https://blog.csdn.net/u011511587/article/details/52063663
void dpxAlgorithmFun::DistanceSegToSeg(CCVector3 ptA,CCVector3 ptB,CCVector3 ptC,CCVector3 ptD,
										double& dDistance,double& dRatioAB,double& dRatioCD,bool bToRay/*=false*/)
{
	return DistanceSegToSeg(ptA.x,ptA.y,ptA.z,
							ptB.x,ptB.y,ptB.z,
							ptC.x,ptC.y,ptC.z,
							ptD.x,ptD.y,ptD.z,
							dDistance,dRatioAB,
							dRatioCD,bToRay);
}

//原理参见博客https://blog.csdn.net/u011511587/article/details/52063663
void dpxAlgorithmFun::DistanceSegToSeg(double x1, double y1, double z1,
										double x2, double y2, double z2,
										double x3, double y3, double z3,
										double x4, double y4, double z4,
										double& dDistance,double& dRatio12,
										double& dRatio34,bool bToRay /*=false*/)
{
    // 解析几何通用解法，可以求出点的位置，判断点是否在线段上
    // 算法描述：设两条无限长度直线s、t,起点为s0、t0，方向向量为u、v
    // 最短直线两点：在s1上为s0+sc*u，在t上的为t0+tc*v
    // 记向量w为(s0+sc*u)-(t0+tc*v),记向量w0=s0-t0
    // 记a=u*u，b=u*v，c=v*v，d=u*w0，e=v*w0——(a)；
    // 由于u*w=、v*w=0，将w=-tc*v+w0+sc*u带入前两式得：
    // (u*u)*sc - (u*v)*tc = -u*w0  (公式2)
    // (v*u)*sc - (v*v)*tc = -v*w0  (公式3)
    // 再将前式(a)带入可得sc=(be-cd)/(ac-b2)、tc=(ae-bd)/(ac-b2)——（b）
    // 注意到ac-b2=|u|2|v|2-(|u||v|cosq)2=(|u||v|sinq)2不小于0
    // 所以可以根据公式（b）判断sc、tc符号和sc、tc与1的关系即可分辨最近点是否在线段内
    // 当ac-b2=0时，(公式2)(公式3)独立，表示两条直线平行。可令sc=0单独解出tc
    // 最终距离d（L1、L2）=|（P0-Q0)+[(be-cd)*u-(ae-bd)v]/(ac-b2)|

    CCVector3 AB(x2-x1,y2-y1,z2-z1); //ux uy uz
	CCVector3 CD(x4-x3,y4-y3,z4-z3); //vx vy vz
	CCVector3 CA(x1-x3,y1-y3,z1-z3); //wx wy wz

	double ux = x2 - x1; //AB.x
    double uy = y2 - y1; //AB.y
    double uz = z2 - z1; //AB.z

    double vx = x4 - x3; //CD.x
    double vy = y4 - y3; //CD.y
    double vz = z4 - z3; //CD.z

    double wx = x1 - x3; //CA.x
    double wy = y1 - y3;
    double wz = z1 - z3;


    double a = (ux * ux + uy * uy + uz * uz); //u*u
    double b = (ux * vx + uy * vy + uz * vz); //u*v
    double c = (vx * vx + vy * vy + vz * vz); //v*v
    double d = (ux * wx + uy * wy + uz * wz); //u*w
    double e = (vx * wx + vy * wy + vz * wz); //v*w
    double dt = a * c - b * b; //s、t分母

    double sd = dt;  //s 分母
    double td = dt;  //t 分母

    double sn = 0.0;//sn = be-cd //分子
    double tn = 0.0;//tn = ae-bd  //分子

    if (IsEqual(dt, 0.0))
    {
        //两直线平行
        sn = 0.0;    //在s上指定取s0
        sd = 1.00;   //防止计算时除0错误  //分母

        tn = e;      //按(公式3)求tc
        td = c;
    }
    else
    {
        sn = (b * e - c * d); //s 分子
        tn = (a * e - b * d); //t 分子
        if (sn < 0.0)
        {
            //最近点在s起点以外，同平行条件
            sn = 0.0;
            tn = e;
            td = c;
        }
        else if (sn > sd) //若是射线，则允许
        {
            //最近点在s终点以外(即sc>1,则取sc=1)
            sn = sd;
            tn = e + b; //按(公式3)计算
            td = c;
        }
    }
    if (tn < 0.0)
    {
        //最近点在t起点以外
        tn = 0.0;
        if (-d < 0.0) //按(公式2)计算，如果等号右边小于0，则sc也小于零，取sc=0
            sn = 0.0;
        else if (-d > a) //按(公式2)计算，如果sc大于1，取sc=1
            sn = sd;
        else
        {
            sn = -d;
            sd = a;
        }
    }
    else if (tn > td && !bToRay) //若是射线的话，大于1是允许的
    {
        tn = td;
        if ((-d + b) < 0.0)
            sn = 0.0;
        else if ((-d + b) > a)
            sn = sd;
        else
        {
            sn = (-d + b);
            sd = a;
        }
    }

    double sc = 0.0;
    double tc = 0.0;

    if (IsEqual(sn, 0.0))
        sc = 0.0;
    else
        sc = sn / sd;

    if (IsEqual(tn, 0.0))
        tc = 0.0;
    else
        tc = tn / td;

	dRatio12 = sc;
	dRatio34 = tc;

    double dx = wx + (sc * ux) - (tc * vx);
    double dy = wy + (sc * uy) - (tc * vy);
    double dz = wz + (sc * uz) - (tc * vz);
    dDistance = sqrt( dx * dx + dy * dy + dz * dz );
}

void dpxAlgorithmFun::DistanceSegmentToRay(CCVector3 ptA,CCVector3 ptB,CCVector3 rayAxis,CCVector3 rayOrigin,double& dDistance,double& dSegRatio,CCVector3& nearestPt)
{
	CCVector3 ptC = rayOrigin;
	CCVector3 ptD = rayOrigin + rayAxis;

	double  dtempRatioCD;
	DistanceSegToSeg(ptA,ptB,ptC,ptD,dDistance,dSegRatio,dtempRatioCD,true);
	nearestPt = ptA+dSegRatio*(ptB-ptA);
}


void dpxAlgorithmFun::DistanceLineToRay(ccPolyline* pLine,CCVector3 rayAxis,CCVector3 rayOrigin,double& dDistance,int& nSegNum,double& dSegRatio,CCVector3& nearestPt)
{
	if(pLine==nullptr)
		return;
	CCVector3 ptC = rayOrigin;
	CCVector3 ptD = rayOrigin + rayAxis;

	dDistance = DBL_MAX;//定义最大的double数值
	int nPtSize = pLine->size();
	for(int i =0;i < nPtSize-1;++i)
	{
		CCVector3 ptA =  *(pLine->getPoint(i));
		CCVector3 ptB =  *(pLine->getPoint(i+1));

		double dDis,dRatioAB,dtempRatioCD;
		CCVector3 tempPt;
		DistanceSegToSeg(ptA,ptB,ptC,ptD,dDis,dRatioAB,dtempRatioCD,true);
		if(dDis<dDistance)
		{
			dDistance = dDis;
			nSegNum = i;
			dSegRatio = dRatioAB;
			nearestPt = ptA+dSegRatio*(ptB-ptA);
		}
	}
}

void dpxAlgorithmFun::DistanceLineNodeToRay(ccPolyline* pLine,CCVector3 rayAxis,CCVector3 rayOrigin,double& dDistance,int& nSegNum,double& dSegRatio,CCVector3& nearestPt)
{
	if(pLine==nullptr)
		return;
	//建立射线
	Ray<PointCoordinateType> ray(rayAxis, rayOrigin);

	dDistance = DBL_MAX;//定义最大的double数值
	int nPtSize = pLine->size();
	for(int i =0;i < nPtSize;i++)
	{
		CCVector3 ptA = *(pLine->getPoint(i));

		double dDis,dRatioAB,dtempRatioCD;
		CCVector3 tempPt;
		dDis = sqrt(ray.radialSquareDistance(ptA));
		if(dDis<dDistance)
		{
			dDistance = dDis;
			nSegNum = i;
			dSegRatio = 1;
			nearestPt = ptA;
			ccLog::Warning("bian li dian ");
		}
	}
}



