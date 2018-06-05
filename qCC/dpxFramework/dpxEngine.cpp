
//by duans
#include "dpxEngine.h"

dpxEngine* dpxEngine::Instance()
{
	//在此处初始化
	dpxEngine* instance = new dpxEngine();
	return instance;
}

dpxEngine::dpxEngine()
{

}
