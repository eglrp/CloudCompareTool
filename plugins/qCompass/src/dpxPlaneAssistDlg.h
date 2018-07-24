
#ifndef _dpxPlaneAssist_Dlg_h__
#define _dpxPlaneAssist_Dlg_h__

#pragma once
#include "dpxToolAssistDlg.h"
#include  <ui_PickAssistDlg.h>
//////////////////////////////////////////////////////////////////////////

class  dpxPlaneAssistDlg : public dpxToolAssistDlg
{
	Q_OBJECT
public:
	explicit dpxPlaneAssistDlg(ccTool* pTool);
	virtual ~dpxPlaneAssistDlg();

signals:
	void sigTypeChange(int nType);
	void sigObjTypeChange(int nObjType);

public slots:
	void slotTypeChanged();		//采集模式改变   单选按钮的变化
	void slotComboBoxValueChanged();	//采集的地物改变 下拉框的变化

private:
	Ui_PickAssistDialog dlg;
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
