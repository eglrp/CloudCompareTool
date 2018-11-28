
#include "dpxCrossWalkDlg.h"
//////////////////////////////////////////////////////////////////////////

dpxCrossWalkDlg::dpxCrossWalkDlg(QWidget *parent /*= 0*/, Qt::WindowFlags f /* = 0*/)
	: QDialog(parent,f)
{
	ui.setupUi(this);
}

dpxCrossWalkDlg::~dpxCrossWalkDlg()
{

}

void dpxCrossWalkDlg::getParams(double& dDis,int& nCount)
{
	dDis = ui.lineEdit_Width->text().toDouble();
	nCount = ui.lineEdit_Count->text().toInt();
}

void dpxCrossWalkDlg::HideWidth()
{
	ui.lineEdit_Width->hide();
	ui.label->hide();
}
