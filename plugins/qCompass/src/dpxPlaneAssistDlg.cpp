
#include "dpxPlaneAssistDlg.h"
#include  <QSettings>
#include  <QApplication>
#include  <QMainWindow>
#include  <QWidget>
#include "dpxMapDefine.h"
//////////////////////////////////////////////////////////////////////////

dpxPlaneAssistDlg::dpxPlaneAssistDlg(ccTool* pTool)
	: dpxToolAssistDlg(pTool)
{
	dlg.setupUi(this);
	dlg.radioButton->setChecked(true);

	dlg.comboBox->addItem("Traffic Light",eObj_OfficeLight);
	dlg.comboBox->addItem("Indication On Road",eObj_Indication_OnRoad);
	dlg.comboBox->addItem( "Indication In Space",eObj_Indication_InSpace);

	connect(dlg.radioButton, SIGNAL(clicked()), this, SLOT(slotTypeChanged()));
	connect(dlg.radioButton_2, SIGNAL(clicked()), this, SLOT(slotTypeChanged()));

	//
    connect(dlg.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotComboBoxValueChanged()));
}
dpxPlaneAssistDlg::~dpxPlaneAssistDlg()
{
}

void dpxPlaneAssistDlg::slotTypeChanged()
{
	if(dlg.radioButton->isChecked())
	{
		emit sigTypeChange(0);
	}
	else if(dlg.radioButton_2->isChecked())
	{
		emit sigTypeChange(1);
	}
}

//采集的地物改变 下拉框的变化
void dpxPlaneAssistDlg::slotComboBoxValueChanged()
{
	int  nData = dlg.comboBox->currentData().toInt();
	emit sigObjTypeChange(nData);
}

