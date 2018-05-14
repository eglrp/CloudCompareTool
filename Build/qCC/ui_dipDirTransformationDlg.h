/********************************************************************************
** Form generated from reading UI file 'dipDirTransformationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPDIRTRANSFORMATIONDLG_H
#define UI_DIPDIRTRANSFORMATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DipDirTransformationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *dipDoubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *dipDirDoubleSpinBox;
    QCheckBox *rotateAboutCenterCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DipDirTransformationDialog)
    {
        if (DipDirTransformationDialog->objectName().isEmpty())
            DipDirTransformationDialog->setObjectName(QStringLiteral("DipDirTransformationDialog"));
        DipDirTransformationDialog->resize(220, 140);
        verticalLayout = new QVBoxLayout(DipDirTransformationDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DipDirTransformationDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dipDoubleSpinBox = new QDoubleSpinBox(DipDirTransformationDialog);
        dipDoubleSpinBox->setObjectName(QStringLiteral("dipDoubleSpinBox"));
        dipDoubleSpinBox->setDecimals(3);
        dipDoubleSpinBox->setMaximum(90);

        formLayout->setWidget(0, QFormLayout::FieldRole, dipDoubleSpinBox);

        label_2 = new QLabel(DipDirTransformationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dipDirDoubleSpinBox = new QDoubleSpinBox(DipDirTransformationDialog);
        dipDirDoubleSpinBox->setObjectName(QStringLiteral("dipDirDoubleSpinBox"));
        dipDirDoubleSpinBox->setDecimals(3);
        dipDirDoubleSpinBox->setMaximum(360);

        formLayout->setWidget(1, QFormLayout::FieldRole, dipDirDoubleSpinBox);


        verticalLayout->addLayout(formLayout);

        rotateAboutCenterCheckBox = new QCheckBox(DipDirTransformationDialog);
        rotateAboutCenterCheckBox->setObjectName(QStringLiteral("rotateAboutCenterCheckBox"));

        verticalLayout->addWidget(rotateAboutCenterCheckBox);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(DipDirTransformationDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DipDirTransformationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DipDirTransformationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DipDirTransformationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DipDirTransformationDialog);
    } // setupUi

    void retranslateUi(QDialog *DipDirTransformationDialog)
    {
        DipDirTransformationDialog->setWindowTitle(QApplication::translate("DipDirTransformationDialog", "Dip / dip dir. transformation", nullptr));
        label->setText(QApplication::translate("DipDirTransformationDialog", "Dip", nullptr));
        dipDoubleSpinBox->setSuffix(QApplication::translate("DipDirTransformationDialog", " deg.", nullptr));
        label_2->setText(QApplication::translate("DipDirTransformationDialog", "Dip direction", nullptr));
        dipDirDoubleSpinBox->setSuffix(QApplication::translate("DipDirTransformationDialog", " deg.", nullptr));
        rotateAboutCenterCheckBox->setText(QApplication::translate("DipDirTransformationDialog", "rotate about selection center", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DipDirTransformationDialog: public Ui_DipDirTransformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPDIRTRANSFORMATIONDLG_H
