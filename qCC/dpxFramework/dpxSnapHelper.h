
#ifndef _dpx_SNAPE_HELPER_HEADER_
#define _dpx_SNAPE_HELPER_HEADER_

//by duans  全局的单例
#include <QString>

#include "../../libs/qCC_db/ccHObject.h"
# include "mainwindow.h"
#include "ccGLWindow.h"
// 鼠标捕捉的实现
class dpxSnapHelper
{
public:
	static dpxSnapHelper* Instance();
public:
	//清空所有选择的对象
	void ClearShowObject();
	//查找所有类型的要素
	bool FindAllObjs(ccHObject::Container& vecHObjs,CC_CLASS_ENUM filter=CC_TYPES::POLY_LINE);

	bool ProjectAllObjs(ccHObject::Container& vecHObjs);
	bool ProjectLinesTo2D(ccHObject::Container& vecHLines);

private:
	static dpxSnapHelper* m_instance;
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
