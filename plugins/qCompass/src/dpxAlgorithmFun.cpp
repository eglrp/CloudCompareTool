//by duans

#include "dpxAlgorithmFun.h"

double dpxAlgorithmFun::DistanceOfPointToLine(CCVector3 a, CCVector3 b, CCVector3 s)
{
    double ab = sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0) + pow((a.z - b.z), 2.0));
    double as = sqrt(pow((a.x - s.x), 2.0) + pow((a.y - s.y), 2.0) + pow((a.z - s.z), 2.0));
    double bs = sqrt(pow((s.x - b.x), 2.0) + pow((s.y - b.y), 2.0) + pow((s.z - b.z), 2.0));
    double cos_A = (pow(as,2.0) + pow(ab,2.0) - pow(bs,2.0)) / (2*ab*as);
    double sin_A = sqrt(1 - pow(cos_A, 2.0));

    return as * sin_A;
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

double dpxAlgorithmFun::rotationAngle(CCVector3 befor, CCVector3 after)
{
    double Dot = befor[0] * after[0] + befor[1] * after[1] + befor[2] * after[2];
	double Before = sqrt(befor[0] * befor[0] + befor[1] * befor[1] + befor[2] *befor[2]);
	double After = sqrt(after[0] * after[0] + after[1] * after[1] + after[2] * after[2]);

    return acos(Dot/Before/After);
}

//求向量的模
double dpxAlgorithmFun::Normalize(CCVector3 v)
{
    return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
}

CCVector3 dpxAlgorithmFun::NormalVec(CCVector3 vec3)
{
	CCVector3 vResult;
	double length = Normalize(vec3);
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

double* dpxAlgorithmFun::translateMatrix(double dX,double dY,double dZ)
{
	double *rotatinMatrix= (double*) malloc(16*sizeof(double));

	rotatinMatrix[0] = 1; 	rotatinMatrix[1] = 0; 	rotatinMatrix[2] = 0; 	rotatinMatrix[3] = 0;
	rotatinMatrix[4] = 0; 	rotatinMatrix[5] = 1; 	rotatinMatrix[6] = 0;	rotatinMatrix[7] = 0;
	rotatinMatrix[8] = 0; 	rotatinMatrix[9] = 0; 	rotatinMatrix[10]= 1;	rotatinMatrix[11] = 0;
	rotatinMatrix[12]=dX; 	rotatinMatrix[13]=dY; 	rotatinMatrix[14]=dZ;	rotatinMatrix[15] = 1;

	return rotatinMatrix;
}

//double* dpxCylinderTool::rotateMatrix(const CCVector3& a_axis,const double& dAngleRad,double dX ,double dY,double dZ)
double* dpxAlgorithmFun::rotateMatrix(const CCVector3& a_axis,const double& dAngleRad)
{
	double *rotatinMatrix= (double *) malloc(16*sizeof(double));
//	// compute length of axis vector
	double length = Normalize(a_axis);

	// normalize axis vector
	double f = 1.0 / length;
	double x = f * a_axis[0];
	double y = f * a_axis[1];
	double z = f * a_axis[2];

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
