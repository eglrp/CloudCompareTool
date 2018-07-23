
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

public slots:
	void slotTypeChanged();

private:
	Ui_PickAssistDialog dlg;
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
