
#include "dpxVisibleSetting.h"

//Local
#include "mainwindow.h"

//qCC_db
#include <ccLog.h>
#include <ccPolyline.h>
#include <ccGenericPointCloud.h>
#include <ccPointCloud.h>
#include <ccMesh.h>
#include <ccHObjectCaster.h>
//qCC_gl
#include <ccGLWindow.h>
#include <ScalarField.h>
//System
#include <assert.h>

dpxVisibleSetting:: dpxVisibleSetting(ccGLWindow* associatedWin,QWidget* parent/*=0*/)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_associatedWin = associatedWin;
	ui.radioButton_Hide->setChecked(true);

	//
	ui.comboBox_Scalar->setEnabled(false);
	ui.sBox_lowScalar->setEnabled(false);
	ui.sBox_HighScalar->setEnabled(false);

	ui.comboBox_Dim->setEnabled(false);
	ui.sBox_LowDim->setEnabled(false);
	ui.sBox_HighDim->setEnabled(false);
	connect(ui.cBox_Scalar,SIGNAL(clicked()),this,SLOT(slotCBoxChanged()));
	connect(ui.cBox_Dim,SIGNAL(clicked()),this,SLOT(slotCBoxChanged()));
}

dpxVisibleSetting::~dpxVisibleSetting()
{
}

void dpxVisibleSetting::slotCBoxChanged()
{
	bool bCBoxScalar = ui.cBox_Scalar->isChecked();
	bool bCBoxDim = ui.cBox_Dim->isChecked();

	ui.comboBox_Scalar->setEnabled(bCBoxScalar);
	ui.sBox_lowScalar->setEnabled(bCBoxScalar);
	ui.sBox_HighScalar->setEnabled(bCBoxScalar);

	ui.comboBox_Dim->setEnabled(bCBoxDim);
	ui.sBox_LowDim->setEnabled(bCBoxDim);
	ui.sBox_HighDim->setEnabled(bCBoxDim);
}


void dpxVisibleSetting::removeAllEntities()
{
	for (QSet<ccHObject*>::const_iterator p = m_toSetVisible.constBegin(); p != m_toSetVisible.constEnd(); ++p)
	{
		ccHObjectCaster::ToGenericPointCloud(*p)->unallocateVisibilityArray();
	}

	m_toSetVisible.clear();
	m_ScalarFields.clear();
}


bool dpxVisibleSetting::setSelectEntitys(ccHObject::Container selectedEntities)
{
	removeAllEntities();

	for(int i= 0;i<selectedEntities.size();i++)
	{
		addEntity(selectedEntities[i]);
	}

	QSet<ccHObject*>::iterator itor = m_toSetVisible.begin();
	for( ;itor != m_toSetVisible.end();itor++)
	{
		ccPointCloud* cloud = ccHObjectCaster::ToPointCloud(*itor);
		if (!cloud)
			continue;

		unsigned sfCount = cloud->getNumberOfScalarFields();
		for(int j =0;j < sfCount;j++)
		{
			 CCLib::ScalarField* pScalarField = cloud->getScalarField(j);
			 m_ScalarFields.insert(pScalarField->getName());
		}
	}

	AddScalarCombobox(m_ScalarFields);
	return true;
}

void dpxVisibleSetting::AddScalarCombobox(QSet<QString> ScalarFields)
{
	ui.comboBox_Scalar->clear();
	QSet<QString>::iterator itor = ScalarFields.begin();
	for( ;itor != ScalarFields.end();itor++)
	{
		QString strScalar = *itor;
		ui.comboBox_Scalar->addItem(strScalar);
	}
}

VSparam dpxVisibleSetting::getParams()
{
	VSparam Param;
	//hide or show
	bool bIsHide = ui.radioButton_Hide->isChecked();
	if(bIsHide)
		Param.m_nHideOrShow = 0;
	else
		Param.m_nHideOrShow = 1;

	//Z
	Param.m_bSetDim = ui.cBox_Dim->isChecked();   //refLine
	Param.m_dLowDim = ui.sBox_LowDim->text().toDouble();
	Param.m_dHighDim = ui.sBox_HighDim->text().toDouble();
	QString strDim = ui.comboBox_Dim->currentText();
	if(strDim=="X")
		Param.m_Dim = 0;
	else if(strDim=="Y")
		Param.m_Dim = 1;
	else if(strDim=="Z")
		Param.m_Dim = 2;

	//Label
	Param.m_bSetScalar = ui.cBox_Scalar->isChecked();   //refLine
	Param.m_strScalar = ui.comboBox_Scalar->currentText();
    Param.m_dLowScalar = ui.sBox_lowScalar->text().toDouble();
    Param.m_dHighScalar = ui.sBox_HighScalar->text().toDouble();

    return Param;
}

void dpxVisibleSetting::accept()
{
	VSparam param = getParams();

	unsigned char ucDim = param.m_Dim;//X=0, Y=1, Z=2
	QString strScalar = param.m_strScalar;

	bool bHide = (param.m_nHideOrShow==0);
	unsigned char visibilityState = bHide? POINT_HIDDEN : POINT_VISIBLE;

	bool bCloud = false;
	int nScalarCount = -1 ;
	int nScalarIndex = -1 ;

	//for each selected entity
	for (QSet<ccHObject*>::const_iterator p = m_toSetVisible.constBegin(); p != m_toSetVisible.constEnd(); ++p)
	{
		ccGenericPointCloud* cloud = ccHObjectCaster::ToGenericPointCloud(*p);
		assert(cloud);

		ccPointCloud* ccloud = ccHObjectCaster::ToPointCloud(*p);
		if(param.m_bSetScalar && ccloud)
		{
			bCloud = true;
			nScalarCount = ccloud->getNumberOfScalarFields();
			nScalarIndex = ccloud->getScalarFieldIndexByName(strScalar.toLatin1().data());
		}

		ccGenericPointCloud::VisibilityTableType* visibilityArray = cloud->getTheVisibilityArray();
		assert(visibilityArray);

		unsigned cloudSize = cloud->size();
		const CCVector3* P3D = nullptr;
		for (int i = 0; i < static_cast<int>(cloudSize); ++i)
		{
			bool bPtChanged = false;
			P3D = cloud->getPoint(i);

			//条件1 XYZ范围隐藏
			if(param.m_bSetDim)
			{
				double dHigh = P3D->u[ucDim]; //unsigned char heightDim
				if( dHigh<=param.m_dHighDim && dHigh>=param.m_dLowDim)
				{
					visibilityArray->setValue(i,visibilityState); //POINT_HIDDEN : POINT_VISIBLE
					bPtChanged = true;
				}
			}

			//条件2 Saclar过滤
			if(param.m_bSetScalar && bCloud)
			{
				if(nScalarIndex>-1 && nScalarIndex < nScalarCount)
				{
					ScalarType dValue  = ccloud->getPointScalarValueV2(nScalarIndex,i);
					if( dValue<=param.m_dHighScalar && dValue>=param.m_dLowScalar)
					{
						visibilityArray->setValue(i,visibilityState); //POINT_HIDDEN : POINT_VISIBLE
						bPtChanged = true;
					}
				}
			}
			//若仅符合条件的显示，则不符合条件的，还需要进一步隐藏
			if(!bHide && !bPtChanged)
			{
				visibilityArray->setValue(i,POINT_HIDDEN);
			}
		}
	}

	reject();
}

void dpxVisibleSetting::reject()
{
	if(m_associatedWin!=nullptr)
		m_associatedWin->redraw(false,false);

	hide();
}

bool dpxVisibleSetting::addEntity(ccHObject* entity)
{
	if(m_associatedWin==nullptr)
		return false;

	if (!entity->isDisplayedIn(m_associatedWin))
	{
		ccLog::Warning(QString("[Graphical Segmentation Tool] Entity [%1] is not visible in the active 3D view!").arg(entity->getName()));
	}

	bool result = false;
	if (entity->isKindOf(CC_TYPES::POINT_CLOUD))
	{
		ccGenericPointCloud* cloud = ccHObjectCaster::ToGenericPointCloud(entity);
		//detect if this cloud is in fact a vertex set for at least one mesh
		{
			//either the cloud is the child of its parent mesh
			if (cloud->getParent() && cloud->getParent()->isKindOf(CC_TYPES::MESH) && ccHObjectCaster::ToGenericMesh(cloud->getParent())->getAssociatedCloud() == cloud)
			{
				ccLog::Warning(QString("[Graphical Segmentation Tool] Can't segment mesh vertices '%1' directly! Select its parent mesh instead!").arg(entity->getName()));
				return false;
			}
			//or the parent of its child mesh!
			ccHObject::Container meshes;
			if (cloud->filterChildren(meshes,false,CC_TYPES::MESH) != 0)
			{
				for (unsigned i=0; i<meshes.size(); ++i)
					if (ccHObjectCaster::ToGenericMesh(meshes[i])->getAssociatedCloud() == cloud)
					{
						ccLog::Warning(QString("[Graphical Segmentation Tool] Can't segment mesh vertices '%1' directly! Select its child mesh instead!").arg(entity->getName()));
						return false;
					}
			}
		}

		cloud->resetVisibilityArray();
		m_toSetVisible.insert(cloud);

		//automatically add cloud's children
		for (unsigned i=0; i<entity->getChildrenNumber(); ++i)
			result |= addEntity(entity->getChild(i));
	}
	else if (entity->isKindOf(CC_TYPES::MESH))
	{
		if (entity->isKindOf(CC_TYPES::PRIMITIVE))
		{
			ccLog::Warning("[ccGraphicalSegmentationTool] Can't segment primitives yet! Sorry...");
			return false;
		}
		if (entity->isKindOf(CC_TYPES::SUB_MESH))
		{
			ccLog::Warning("[ccGraphicalSegmentationTool] Can't segment sub-meshes! Select the parent mesh...");
			return false;
		}
		else
		{
			ccGenericMesh* mesh = ccHObjectCaster::ToGenericMesh(entity);

			//first, we must check that there's no mesh and at least one of its sub-mesh mixed in the current selection!
			for (QSet<ccHObject*>::const_iterator p = m_toSetVisible.constBegin(); p != m_toSetVisible.constEnd(); ++p)
			{
				if ((*p)->isKindOf(CC_TYPES::MESH))
				{
					ccGenericMesh* otherMesh = ccHObjectCaster::ToGenericMesh(*p);
					if (otherMesh->getAssociatedCloud() == mesh->getAssociatedCloud())
					{
						if ((otherMesh->isA(CC_TYPES::SUB_MESH) && mesh->isA(CC_TYPES::MESH))
							|| (otherMesh->isA(CC_TYPES::MESH) && mesh->isA(CC_TYPES::SUB_MESH)))
						{
							ccLog::Warning("[Graphical Segmentation Tool] Can't mix sub-meshes with their parent mesh!");
							return false;
						}
					}
				}
			}

			mesh->getAssociatedCloud()->resetVisibilityArray();
			m_toSetVisible.insert(mesh);
			result = true;
		}
	}
	else if (entity->isA(CC_TYPES::HIERARCHY_OBJECT))
	{
		//automatically add entity's children
		for (unsigned i=0;i<entity->getChildrenNumber();++i)
			result |= addEntity(entity->getChild(i));
	}

	return result;
}
