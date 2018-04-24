
#include "dpxAttributeEditDlg.h"

//system
#include <assert.h>


dpxAttributeEditDlg::dpxAttributeEditDlg(QWidget* parent)
	: QDialog(parent, Qt::Tool)
{
	ui.setupUi(this);

	//glassTypeChanged(glassTypeComboBox->currentIndex());

	//connect(glassTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(glassTypeChanged(int)));
}
void dpxAttributeEditDlg::setAttrFields(QStringList Fields)
{
	int nSize = Fields.size();
	for(int i = 0;i < nSize;i++)
	{
		QLabel* Field1Label = new QLabel(ui.groupBox);
		Field1Label->setText(Fields.at(i));
        ui.gridLayout->addWidget(Field1Label, i, 0, 1, 1);

        QSpacerItem* horizontalSpacer = new QSpacerItem(12, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);
        ui.gridLayout->addItem(horizontalSpacer, i, 1, 1, 1);

        QLineEdit* lineEdit_Field1 = new QLineEdit(ui.groupBox);
        ui.gridLayout->addWidget(lineEdit_Field1, i, 2, 1, 1);

		structLabelLine struLabel;
		struLabel.pLabel = Field1Label;
		struLabel.pItem = horizontalSpacer;
		struLabel.pEdit = lineEdit_Field1;
		m_labelAndLines.push_back(struLabel);
	}

	ui.groupBox->resize(235,(nSize+2)*33);
}

void dpxAttributeEditDlg::getAttrFields(QMap<QString, QVariant>& keyValue)
{
	keyValue.clear();
	int nSize = m_labelAndLines.size();
	for(int i = 0;i < nSize;i++)
	{
		QString strKey = m_labelAndLines[i].pLabel->text();
		QString strValue = m_labelAndLines[i].pEdit->text();
		keyValue[strKey] = QVariant(strValue);
	}

	//ui.groupBox->resize(235,(nSize+2)*33);
}
