
#include "dpxPlaneAssistDlg.h"
#include  <QSettings>
#include  <QApplication>
#include  <QMainWindow>
#include  <QWidget>
//////////////////////////////////////////////////////////////////////////

dpxPlaneAssistDlg::dpxPlaneAssistDlg(ccTool* pTool)
	: dpxToolAssistDlg(pTool)
{
	dlg.setupUi(this);
	dlg.radioButton->setChecked(true);
	connect(dlg.radioButton, SIGNAL(clicked()), this, SLOT(slotTypeChanged()));
	connect(dlg.radioButton_2, SIGNAL(clicked()), this, SLOT(slotTypeChanged()));
}
dpxPlaneAssistDlg::~dpxPlaneAssistDlg()
{
}

void dpxPlaneAssistDlg::slotTypeChanged()
{
	if(dlg.radioButton->isChecked())
	{
		emit sigTypeChange(0);
		ccLog::Warning("radioBtn");
	}
	else if(dlg.radioButton_2->isChecked())
	{
		emit sigTypeChange(1);
		ccLog::Warning("radioButton_2");
	}

}

