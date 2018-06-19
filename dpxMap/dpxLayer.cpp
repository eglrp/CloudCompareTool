
#include "dpxLayer.h"
dpxLayer::dpxLayer(QString sName,QString sLyrID)
{
	//构造时产生QUuid
	m_strLryID = sLyrID;//QUuid::createUuid().toString();
	m_lyrRootData = new ccHObject(sName);
}

dpxLayer::dpxLayer(QString sName)
{
	//构造时产生QUuid
	m_strLryID = QUuid::createUuid().toString();
	m_lyrRootData = new ccHObject(sName);
}

dpxLayer::~dpxLayer()
{
}

QString dpxLayer::getLayerName()
{
	return m_lyrRootData->getName();
}

void dpxLayer::setLayerName(QString sName)
{
	m_lyrRootData->setName(sName);
}

void dpxLayer::setLayerID(QString sID)
{
	m_strLryID = sID;
}

QString dpxLayer::getLayerID()
{
	return m_strLryID;
}

//只能访问根节点数据，不能编辑
 ccHObject* dpxLayer::getRootData()
{
	return m_lyrRootData;
}
//增要素
bool dpxLayer::AddFeature(ccHObject* pFeature)
{
	return m_lyrRootData->addChild(pFeature);
	//return false;
}

bool dpxLayer::AddFeatures(HObjectVec vFeatures)
{
	bool bSuccess = true;
	for(int i = 0;i<vFeatures.size();i++)
	{
		if(!m_lyrRootData->addChild(vFeatures[i]))
			bSuccess = false;
	}
	return bSuccess;
}
//删要素
bool dpxLayer::DeleteAllFeatures()
{
	m_lyrRootData->removeAllChildren();
	return (m_lyrRootData->getChildrenNumber()==0);
}

void dpxLayer::deleteFeature(ccHObject* pFeature)
{
	m_lyrRootData->removeChild(pFeature);
}

void dpxLayer::deleteFeatures(HObjectVec vFeatures)
{
	bool bSuccess = true;
	for(int i = 0;i<vFeatures.size();i++)
	{
		m_lyrRootData->removeChild(vFeatures[i]);
	}
}


unsigned dpxLayer::getChildrenNumber() const
{
	return m_lyrRootData->getChildrenNumber();
}

ccHObject* dpxLayer::getChild(unsigned childPos) const
{
	return m_lyrRootData->getChild(childPos);
}

ccHObject* dpxLayer::find(unsigned uniqueID)
{
	return m_lyrRootData->find(uniqueID);
}
