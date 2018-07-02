
#ifndef _dpx_SNAPE_HELPER_HEADER_
#define _dpx_SNAPE_HELPER_HEADER_

//by duans  全局的单例
#include <QString>
#include <QObject>

# include "CCTypes.h"
#include "ccHObject.h"
#include "mainwindow.h"
#include "ccGLWindow.h"
#include "ccPolyline.h"
#include "ccPointCloud.h"
#include "RayAndBox.h"

// 鼠标捕捉的实现
class dpxSnapHelper : public QObject
{
public:
	static dpxSnapHelper* Instance();
public:
	//清空所有选择的对象
	void ClearShowObject();

	//bOnlyOne代表是否清除其它临时显示项
	void AddTempShowObject(ccHObject* pTempShowObj,bool bOnlyOne = true);

	//查找所有类型的要素（默认查找线）
	bool FindAllObjs(ccHObject::Container& vecHObjs,CC_CLASS_ENUM filter=CC_TYPES::POLY_LINE);

	//线的节点投影到屏幕上
	bool ProjectLinesTo2D(ccHObject::Container& vec3DLines,ccHObject::Container& vec2DLines);

	//box是否与射线相交
	bool isBoxIntersectWithRay(ccBBox box,Ray<float> ray);

private:
	//当前激活的ccGLWindow
	ccGLWindow* m_pCurActiveWindow;
	//捕捉的效果图形存储在根几何上
	ccHObject* m_pShowRootObject;

//私有构造
private:
	dpxSnapHelper();
	dpxSnapHelper(const dpxSnapHelper&){}
	dpxSnapHelper& operator=(const dpxSnapHelper&){}
};


#endif //dpxSnapHelper
