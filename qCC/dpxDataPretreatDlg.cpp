
#include "dpxDataPretreatDlg.h"
#include <QFileDialog>
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

dpxDataPretreatDlg:: dpxDataPretreatDlg(QWidget* parent/*=0*/)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.tileGroupBox, SIGNAL(toggled(bool)), ui.applyButton, SLOT(setEnabled(bool)));
	connect(ui.applyButton, SIGNAL(clicked()), this, SLOT(onApplyAll()));
	connect(ui.browseToolButton, SIGNAL(clicked()), this, SLOT(onOutPathBrowse()));
	connect(ui.browseToolButton_input, SIGNAL(clicked()), this, SLOT(onInPathBrowse()));

	//can't use the 'Apply all' button if tiling mode is enabled
	ui.tileGroupBox->setChecked(true);
	ui.applyButton->setEnabled(ui.tileGroupBox->isChecked());
}

pdxPretreatParams  dpxDataPretreatDlg::getParam()
{
	pdxPretreatParams param;
	param.strInputPath = ui.inputPathLineEdit->text();
	param.strOutputPath = ui.outputPathLineEdit->text();

	//tiling (vertical) dimension
	param.vertDim = 2;
	switch (ui.tileDimComboBox->currentIndex())
	{
	case 0: //XY
		param.vertDim = 2;
		break;
	case 1: //XZ
		param.vertDim = 1;
		break;
	case 2: //YZ
		param.vertDim = 0;
		break;
	}
	param.w = static_cast<unsigned int>( ui.wTileSpinBox->value() );
	param.h = static_cast<unsigned int>( ui.hTileSpinBox->value() );

	//降采样比率
	param.nDownSamplingRatio = static_cast<unsigned int>(ui.DownSamplingRatio->value());

	return param;
}


void dpxDataPretreatDlg::onApplyAll()
{
	pdxPretreatParams  param = getParam();

	dpxDataPretreat* pDataPretreat = new dpxDataPretreat();
	pDataPretreat->setPretreatParam(param);
	pDataPretreat->PretreatFiles();
}

void dpxDataPretreatDlg::onInPathBrowse()
{
	QString inputPath = QFileDialog::getExistingDirectory(this, "Output path", ui.inputPathLineEdit->text());
	if (inputPath.isEmpty())
		return;

	ui.inputPathLineEdit->setText(inputPath);
}

void dpxDataPretreatDlg::onOutPathBrowse()
{
	QString outputPath = QFileDialog::getExistingDirectory(this, "Output path", ui.outputPathLineEdit->text());
	if (outputPath.isEmpty())
		return;

	ui.outputPathLineEdit->setText(outputPath);
}

dpxDataPretreatDlg::~dpxDataPretreatDlg()
{
}


void dpxDataPretreatDlg::accept()
{

}

void dpxDataPretreatDlg::reject()
{
	hide();
}
