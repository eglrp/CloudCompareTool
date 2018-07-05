
//by duans
#include "dpxSelectionManager.h"

dpxSelectionManager* dpxSelectionManager::Instance()
{
	static dpxSelectionManager instance;
	return &instance;
}

dpxSelectionManager::dpxSelectionManager()
{
	m_vecSeltHObjs.clear();
	MainWindow* pMainWindow = MainWindow::TheInstance();
	if(pMainWindow==nullptr || pMainWindow==0)
	{
		ccLog::Warning("no current Main Window");
		return;
	}
	m_pCurActiveWindow = pMainWindow->getActiveGLWindow();
	if(m_pCurActiveWindow!=nullptr)
	{
		m_pShowSelectObject = new ccHObject("RootShow");
		m_pCurActiveWindow->addToOwnDB(m_pShowSelectObject);
	}
}

bool dpxSelectionManager::IsEmpty()
{
    return m_vecSeltHObjs.empty();
}

//清空所有选择的对象
void dpxSelectionManager::ClearSelection()
{
	rebackColor();
	m_vecSeltHObjs.clear();
}


void dpxSelectionManager::AddObject2Selection(ccHObject* pHObject,bool bOnlyOne/*=true*/)
{
	//若已存在，则返回
	if(isInSelectSet(pHObject))
		return;

	rebackColor();

	if(bOnlyOne)
		m_vecSeltHObjs.clear();

	m_vecSeltHObjs.push_back(pHObject);
}

bool dpxSelectionManager::isInSelectSet(ccHObject* pHObject)
{
	if(m_vecSeltHObjs.size()==0)
		return false;

	for(int i= 0;i<m_vecSeltHObjs.size();i++)
	{
		if(m_vecSeltHObjs[i] == pHObject)
			return true;
	}

	return false;
}

void dpxSelectionManager::RemoveSelection(ccHObject* pHObject)
{
	if(m_vecSeltHObjs.size()==0)
		return;

	rebackColor();

	vector<ccHObject*>::iterator iter = m_vecSeltHObjs.end();
	while( iter != m_vecSeltHObjs.begin())
    {
       if(*(--iter)==pHObject)
       {
			m_vecSeltHObjs.erase(iter);
       }
    }
}

//线被选中时颜色改成了红色，现在要统一恢复到白色
void dpxSelectionManager::rebackColor()
{
	for(int i =0;i < m_vecSeltHObjs.size();i++)
	{
		ccHObject* pObj = m_vecSeltHObjs[i];
		if(!pObj->isKindOf(CC_TYPES::POLY_LINE))
			continue;
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pObj);
		if(pLine==nullptr)
			continue;

		pLine->setTempColor(ccColor::white);
	}
}

void dpxSelectionManager::redrawSelectionSet()
{
	//清空捕捉效果
	m_pShowSelectObject->removeAllChildren();
	if(m_vecSeltHObjs.size()==0)
		return;

	for(int i =0;i < m_vecSeltHObjs.size();i++)
	{
		ccHObject* pObj = m_vecSeltHObjs[i];
		if(!pObj->isKindOf(CC_TYPES::POLY_LINE))
			continue;
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pObj);
		if(pLine==nullptr)
			continue;

		pLine->setTempColor(ccColor::red);
		int nSize = pLine->size();
		for(int i=0;i<nSize;i++)
		{
			const CCVector3* pPoint = pLine->getPoint(i);
			//一个移动的小球
			ccGLMatrix transM ;
			CCVector3 vecTrans(pPoint->x,pPoint->y,pPoint->z);
			transM.setTranslation(vecTrans);
			//-----------------------以下方法可行-------------------------------//
			ccSphere* pSphere = new ccSphere(0.2,&transM,"Sphere",2);
			pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
			pSphere->setTempColor(ccColor::red);
			pSphere->setVisible(true);
			pSphere->setEnabled(true);
			m_pShowSelectObject->addChild(pSphere);
		}
	}
	m_pCurActiveWindow->redraw(false, false); //只刷新2D->
}
