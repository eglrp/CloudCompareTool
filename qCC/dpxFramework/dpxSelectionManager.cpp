
//by duans
#include "dpxSelectionManager.h"
#define DPX_OLD_COLOR  "dpxOldColor"
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

int  dpxSelectionManager::getSelectionSize()
{
    return m_vecSeltHObjs.size();
}

//清空所有选择的对象
void dpxSelectionManager::ClearSelection()
{
	rebackColor();
	m_vecSeltHObjs.clear();
}


void dpxSelectionManager::AddObject2Selection(vector<ccHObject*> vecHObject,bool bOnlyOne/*=true*/)
{
	//const ccColor::Rgb
	for(int i = 0;i<vecHObject.size();i++)
	{
		const ccColor::Rgba& oldColor =  vecHObject[i]->getTempColor();
		QString colorStr = QString("%1;%2;%3").arg(oldColor.rgba[0]).arg(oldColor.rgba[1]).arg(oldColor.rgba[2]);
		 vecHObject[i]->setMetaData(DPX_OLD_COLOR,colorStr);
	}

	rebackColor();

	if(bOnlyOne)
		m_vecSeltHObjs.clear();

	m_vecSeltHObjs.insert(m_vecSeltHObjs.end(),vecHObject.begin(),vecHObject.end());
}


void dpxSelectionManager::AddObject2Selection(ccHObject* pHObject,bool bOnlyOne/*=true*/)
{
	//若已存在，则返回
	if(isInSelectSet(pHObject))
		return;

		//const ccColor::Rgb
	const ccColor::Rgba& oldColor =  pHObject->getTempColor();
	QString colorStr = QString("%1;%2;%3").arg(oldColor.rgba[0]).arg(oldColor.rgba[1]).arg(oldColor.rgba[2]);
	pHObject->setMetaData(DPX_OLD_COLOR,colorStr);
	ccLog::Warning("set Color:" + colorStr);

	rebackColor();

	if(bOnlyOne)
		m_vecSeltHObjs.clear();

	m_vecSeltHObjs.push_back(pHObject);
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

		//若线记录了原有颜色则恢复至原有颜色
		if(pLine->hasMetaData(DPX_OLD_COLOR))
		{
			//QString colorStr = QString("%1;%2;%3)).arg(oldColor.rgb[0]).arg(oldColor.rgb[1]).arg(oldColor.rgb[2]);
			QString colorStr = pLine->getMetaData(DPX_OLD_COLOR).toString();
			ccLog::Warning("get Color:" + colorStr);
			//Q_REQUIRED_RESULT QString mid(int position, int n = -1) const;
			QStringList strList =  colorStr.split(";");
			if(strList.size()>2)
			{
				int R = strList.at(0).toInt();
				int G = strList.at(1).toInt();
				int B = strList.at(2).toInt();

				ccColor::Rgb rgb(R,G,B);
				pLine->setTempColor(rgb);
			}
		}
		else//默认恢复为白色
		{
			pLine->setTempColor(ccColor::white);
		}
	}
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

		pLine->enableTempColor(true);
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

