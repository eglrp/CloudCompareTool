

// classs name : dpxAttributeEditDlg
// brif: Set Geometry Attribute
// by: duans
// 2018/4/21

#ifndef _dpxAttributeEditDlg_H__
#define _dpxAttributeEditDlg_H__


#include "ui_dpxAttributeEditDlg.h"

//Qt
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
class Ui_dpxAttributeEditDlg;


//! Dialog to define the parameters of the stereo mode (for 3D views)
class dpxAttributeEditDlg : public QDialog
{
	Q_OBJECT
public:
	//! Default constructor
	explicit dpxAttributeEditDlg(QWidget* parent);

	void setAttrFields(QStringList Fields);
	void getAttrFields(QMap<QString, QVariant>& keyValue);

struct structLabelLine
{
public:
	QLabel* pLabel;
	QSpacerItem* pItem;
	QLineEdit* pEdit;
};

protected slots:
	//! Slot called when the glass type is modified
	//void glassTypeChanged(int);

protected:
	Ui::dpxAttributeEditDlg ui;
	std::vector<structLabelLine> m_labelAndLines;
};

#endif //CC_STEREO_MODE_DLG_HEADER
