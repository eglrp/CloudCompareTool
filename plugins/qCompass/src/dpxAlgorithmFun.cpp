//by duans

#include "dpxAlgorithmFun.h"

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
