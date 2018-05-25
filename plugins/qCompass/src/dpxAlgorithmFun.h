//class name:dpxAlgorithmFun
//brif:算法函数
//by duans

#ifndef _DPX_Algorithm_Fun_HEADER_
#define _DPX_Algorithm_Fun_HEADER_

#include "ccGeoObject.h"
#include "math.h"

class dpxAlgorithmFun
{
public:
	//点到线的距离3D
	static double DistanceOfPointToLine(CCVector3 a, CCVector3 b, CCVector3 s);

	//3D 点S投影到线AB上的点
	static CCVector3 PointProjectionToLine(const CCVector3& PtA, const CCVector3& PtB,const CCVector3& PtS);

	//查询点query是否在直径segStart，segEnd圆内部
	static bool inCircle(const CCVector3* segStart, const CCVector3* segEnd, const CCVector3* query);
	//把向量转为单位向量
	static CCVector3 NormalVec(CCVector3 vec3);
	//向量的模
	static double NormalizeValue(CCVector3 v);
	//向量的旋转角度
	static double rotationAngle(CCVector3 befor, CCVector3 after);
	//向量的旋转轴
	static CCVector3 rotationAxis(CCVector3 befor, CCVector3 after);

	//根据XYZ平移求平移矩阵 返回指针用完free
	static double* translateMatrix(double dX,double dY,double dZ);

	//根据旋转轴、旋转角度求旋转矩阵(返回指针用完free)
	static double* rotateMatrix(const CCVector3& a_axis,const double& dAngleRad);
	static double* rotateMatrix(CCVector3 vbefor,CCVector3 vafter);
};

class dpxSystemFun
{
public:
	static QString GetRootDir();
	static QString GetQccImageDir();


};
#endif
