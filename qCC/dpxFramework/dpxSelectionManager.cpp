
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
}

//清空所有选择的对象
void dpxSelectionManager::ClearSelection()
{
	m_vecSeltHObjs.clear();
}

bool dpxSelectionManager::IsEmpty()
{
    return m_vecSeltHObjs.empty();
}

void dpxSelectionManager::AddObject2Selection(ccHObject* pHObject,bool bOnlyOne/*=true*/)
{
	if(bOnlyOne)
		m_vecSeltHObjs.clear();

	m_vecSeltHObjs.push_back(pHObject);
}

void dpxSelectionManager::RemoveSelection(ccHObject* pHObject)
{
	if(m_vecSeltHObjs.size()==0)
		return;

	vector<ccHObject*>::iterator iter = m_vecSeltHObjs.end();
	while( iter != m_vecSeltHObjs.begin())
    {
       if(*(--iter)==pHObject)
       {
			m_vecSeltHObjs.erase(iter);
       }
    }
}

void dpxSelectionManager::redrawSelectionSet()
{
	//清空捕捉效果
	dpxSnapHelper::Instance()->ClearShowObject();
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

		int nSize = pLine->size();
		for(int i=0;i<nSize;i++)
		{
			const CCVector3* pPoint = pLine->getPoint(i);
			//一个移动的小球
			ccGLMatrix transM ;
			CCVector3 vecTrans(pPoint->x,pPoint->y,pPoint->z);
			transM.setTranslation(vecTrans);

			//-----------------------以下方法可行-------------------------------//
			ccSphere* pSphere = new ccSphere(0.1,&transM,"Sphere",4);
			pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
			//pSphere->setDisplay(m_window);
			pSphere->setTempColor(ccColor::red);
			pSphere->setVisible(true);
			pSphere->setEnabled(true);
			dpxSnapHelper::Instance()->AddTempShowObject(pSphere,false);
		}
	}
}
