
#include "dpxFeature.h"

dpxFeature::dpxFeature(ccHObject* pHObject)
{
	m_pGeometry = pHObject;
}

dpxFeature::~dpxFeature()
{
	m_pGeometry = nullptr;
	delete m_pGeometry;
}

void dpxFeature::setGeometry(ccHObject* pGeometry)
{
	m_pGeometry = pGeometry;
}
ccHObject* dpxFeature::getGeometry()
{
	return m_pGeometry;
}

void dpxFeature::setAllMetaData(const QVariantMap& dataset, bool overwrite /*= false*/)
{
	return m_pGeometry->setMetaData(dataset,overwrite);
}

const QVariantMap& dpxFeature::getAllMetaData() const
{
	return m_pGeometry->metaData();
}

QString dpxFeature::getMetaData(QString key) const
{
	return m_pGeometry->getMetaData(key).toString();
}

bool dpxFeature::removeMetaData(QString key)
{
	return m_pGeometry->removeMetaData(key);
}

void dpxFeature::setMetaData(QString key, QVariant data)
{
	return m_pGeometry->setMetaData(key,data);
}

void dpxFeature::setMetaData(QString key, QString data)
{
	QVariant qvt;
	qvt.setValue(data);
 	return m_pGeometry->setMetaData(key,data);
}

bool dpxFeature::hasMetaData(QString key) const
{
	return m_pGeometry->hasMetaData(key);
}


