
//by duans
#include "dpxSnapHelper.h"

dpxSnapHelper* dpxSnapHelper::Instance()
{
	//在此处初始化
	dpxSnapHelper* instance = new dpxSnapHelper();
	return instance;
}

dpxSnapHelper::dpxSnapHelper()
{
	MainWindow* pMainWindow = MainWindow::TheInstance();
	if(pMainWindow==nullptr|| pMainWindow==0)
	{
		ccLog::Warning("no current Main Window");
		return;
	}
	m_pCurActiveWindow = pMainWindow->getActiveGLWindow();
	m_pShowRootObject = new ccHObject("RootShow");
	m_pShowRootObject->setEnabled(false);

	m_pCurActiveWindow->addToOwnDB(m_pShowRootObject);
}

void dpxSnapHelper::ClearShowObject()
{
	if(m_pShowRootObject==nullptr || m_pShowRootObject==0)
		return;

	m_pShowRootObject->removeAllChildren();
}

//获取树状图里所有的线
bool dpxSnapHelper::FindAllObjs(ccHObject::Container& vecHObjs,CC_CLASS_ENUM filter/*= CC_TYPES::POLY_LINE*/)
{
	MainWindow* pMainWindow = MainWindow::TheInstance();
	ccDBRoot* pDBRootModel = pMainWindow->GetDBRoot();
	if(pDBRootModel==nullptr)
		return false;
	ccHObject*pHRoot = pDBRootModel->getRootEntity();
	if(pHRoot==nullptr)
		return false;

	vecHObjs.clear();
	pHRoot->filterChildren(vecHObjs,true,CC_TYPES::POLY_LINE);

	return !vecHObjs.empty();
}

//投影至平面，供屏幕捕捉使用
bool dpxSnapHelper::ProjectLinesTo2D(ccHObject::Container& vecHLines)
{
	if(m_pCurActiveWindow==nullptr || m_pCurActiveWindow==0)
		return false;

	ccGLCameraParameters camera;
	m_pCurActiveWindow->getGLCameraParameters(camera);

	for(int i =0;i<vecHLines.size();i++)
	{
		ccHObject* pHObj = vecHLines[i];
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pHObj);
		if(pLine==nullptr)
			continue;

//		for(int i=0;i<pLine->size();i++)
//		{
//			CCVector3d* P3D = pLine->getPoint(i);
//			CCVector3d P2D(-1,-1,-1);
//			camera.project(*P3D,P2D);
//		}
	}

	return true;
}

//bool ccGLWindow::getClick3DPos(int x, int y, CCVector3d& P3D)
