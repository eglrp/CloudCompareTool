/********************************************************************************
** Form generated from reading UI file 'dpxAttributeEditDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPXATTRIBUTEEDITDLG_H
#define UI_DPXATTRIBUTEEDITDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dpxAttributeEditDlg
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dpxAttributeEditDlg)
    {
        if (dpxAttributeEditDlg->objectName().isEmpty())
            dpxAttributeEditDlg->setObjectName(QStringLiteral("dpxAttributeEditDlg"));
        dpxAttributeEditDlg->resize(251, 118);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dpxAttributeEditDlg->sizePolicy().hasHeightForWidth());
        dpxAttributeEditDlg->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(dpxAttributeEditDlg);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(dpxAttributeEditDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(dpxAttributeEditDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(dpxAttributeEditDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), dpxAttributeEditDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dpxAttributeEditDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(dpxAttributeEditDlg);
    } // setupUi

    void retranslateUi(QDialog *dpxAttributeEditDlg)
    {
        dpxAttributeEditDlg->setWindowTitle(QApplication::translate("dpxAttributeEditDlg", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("dpxAttributeEditDlg", "Attribute Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dpxAttributeEditDlg: public Ui_dpxAttributeEditDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPXATTRIBUTEEDITDLG_H
