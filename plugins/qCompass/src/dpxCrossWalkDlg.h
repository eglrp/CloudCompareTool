
#ifndef _dpxCrossWalkDlg_h_
#define _dpxCrossWalkDlg_h_

#pragma once
#include <QDialog>
#include  <ui_dpxSettingDlg.h>
//////////////////////////////////////////////////////////////////////////

class  dpxCrossWalkDlg : public QDialog
{
	Q_OBJECT
public:
	explicit dpxCrossWalkDlg(QWidget *parent = 0, Qt::WindowFlags f = 0);
	virtual ~dpxCrossWalkDlg();

	void getParams(double& dDis,int& nCount);

	void HideWidth();
private:
	Ui::SettingDialog  ui;
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
