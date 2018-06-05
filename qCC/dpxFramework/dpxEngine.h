
#ifndef _DPX_ENGINE_HEADER_
#define _DPX_ENGINE_HEADER_

//by duans  全局的单例
#include <QString>
#include <QObject>

# include "CCTypes.h"
#include "../../libs/qCC_db/ccHObject.h"
# include "mainwindow.h"
#include "ccGLWindow.h"
#include "ccPolyline.h"
#include "ccPointCloud.h"
// 鼠标捕捉的实现
class dpxEngine : public QObject
{
public:
	static dpxEngine* Instance();
public:

//私有构造
private:
	dpxEngine();
	dpxEngine(const dpxEngine&){}
	dpxEngine& operator=(const dpxEngine&){}
};


#endif //dpxSnapHelper
