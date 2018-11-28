#ifndef _dpx_DataPretreat_Dlg_h_
#define _dpx_DataPretreat_Dlg_h_

//qCC_db
#include <ccHObject.h>

//Qt
#include <QSet>
#include "ui_dpxDataPretreatDlg.h"
#include <dpxDataPretreat.h>

//! Graphical segmentation mechanism (with polyline)
class dpxDataPretreatDlg : public QDialog
{
	Q_OBJECT
public:
	explicit dpxDataPretreatDlg(QWidget* parent=0);
	virtual ~dpxDataPretreatDlg();

	pdxPretreatParams  getParam();

	virtual void accept();
	virtual void reject();
public:
	//bool setSelectEntitys(ccHObject::Container selectedEntities);
	//VSparam getParams();

public slots:
	void onApplyAll();
	void onOutPathBrowse();
	void onInPathBrowse();
protected:
protected:
	Ui::dpxDataPretreatDlg  ui;
};

#endif //CC_GRAPHICAL_SEGMENTATION_TOOLS_HEADER
