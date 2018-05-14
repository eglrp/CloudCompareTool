/********************************************************************************
** Form generated from reading UI file 'scaleDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEDLG_H
#define UI_SCALEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScaleDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QDoubleSpinBox *fxSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label2;
    QDoubleSpinBox *fySpinBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label3;
    QDoubleSpinBox *fzSpinBox;
    QCheckBox *sameForAllCheckBox;
    QCheckBox *keepInPlaceCheckBox;
    QCheckBox *rescaleGlobalShiftCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScaleDialog)
    {
        if (ScaleDialog->objectName().isEmpty())
            ScaleDialog->setObjectName(QStringLiteral("ScaleDialog"));
        ScaleDialog->resize(550, 150);
        verticalLayout = new QVBoxLayout(ScaleDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label1 = new QLabel(ScaleDialog);
        label1->setObjectName(QStringLiteral("label1"));

        horizontalLayout->addWidget(label1);

        fxSpinBox = new QDoubleSpinBox(ScaleDialog);
        fxSpinBox->setObjectName(QStringLiteral("fxSpinBox"));
        fxSpinBox->setDecimals(8);
        fxSpinBox->setMinimum(-1e+6);
        fxSpinBox->setMaximum(1e+6);

        horizontalLayout->addWidget(fxSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label2 = new QLabel(ScaleDialog);
        label2->setObjectName(QStringLiteral("label2"));

        horizontalLayout->addWidget(label2);

        fySpinBox = new QDoubleSpinBox(ScaleDialog);
        fySpinBox->setObjectName(QStringLiteral("fySpinBox"));
        fySpinBox->setDecimals(8);
        fySpinBox->setMinimum(-1e+6);
        fySpinBox->setMaximum(1e+6);

        horizontalLayout->addWidget(fySpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label3 = new QLabel(ScaleDialog);
        label3->setObjectName(QStringLiteral("label3"));

        horizontalLayout->addWidget(label3);

        fzSpinBox = new QDoubleSpinBox(ScaleDialog);
        fzSpinBox->setObjectName(QStringLiteral("fzSpinBox"));
        fzSpinBox->setDecimals(8);
        fzSpinBox->setMinimum(-1e+6);
        fzSpinBox->setMaximum(1e+6);

        horizontalLayout->addWidget(fzSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        sameForAllCheckBox = new QCheckBox(ScaleDialog);
        sameForAllCheckBox->setObjectName(QStringLiteral("sameForAllCheckBox"));

        verticalLayout->addWidget(sameForAllCheckBox);

        keepInPlaceCheckBox = new QCheckBox(ScaleDialog);
        keepInPlaceCheckBox->setObjectName(QStringLiteral("keepInPlaceCheckBox"));

        verticalLayout->addWidget(keepInPlaceCheckBox);

        rescaleGlobalShiftCheckBox = new QCheckBox(ScaleDialog);
        rescaleGlobalShiftCheckBox->setObjectName(QStringLiteral("rescaleGlobalShiftCheckBox"));
        rescaleGlobalShiftCheckBox->setChecked(true);

        verticalLayout->addWidget(rescaleGlobalShiftCheckBox);

        verticalSpacer = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ScaleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ScaleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ScaleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ScaleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScaleDialog);
    } // setupUi

    void retranslateUi(QDialog *ScaleDialog)
    {
        ScaleDialog->setWindowTitle(QApplication::translate("ScaleDialog", "Scale / multiply", nullptr));
        label1->setText(QApplication::translate("ScaleDialog", "Scale(x)", nullptr));
        label2->setText(QApplication::translate("ScaleDialog", "Scale(y)", nullptr));
        label3->setText(QApplication::translate("ScaleDialog", "Scale(z)", nullptr));
#ifndef QT_NO_TOOLTIP
        sameForAllCheckBox->setToolTip(QApplication::translate("ScaleDialog", "Same scale for all dimensions", nullptr));
#endif // QT_NO_TOOLTIP
        sameForAllCheckBox->setText(QApplication::translate("ScaleDialog", "Same scale for all dimensions", nullptr));
#ifndef QT_NO_TOOLTIP
        keepInPlaceCheckBox->setToolTip(QApplication::translate("ScaleDialog", "Whether the cloud (center) should stay at the same place or not (i.e. coordinates are multiplied directly)", nullptr));
#endif // QT_NO_TOOLTIP
        keepInPlaceCheckBox->setText(QApplication::translate("ScaleDialog", "Keep entity in place", nullptr));
#ifndef QT_NO_TOOLTIP
        rescaleGlobalShiftCheckBox->setToolTip(QApplication::translate("ScaleDialog", "To apply the same scale(s) to the 'Global Shift' as well", nullptr));
#endif // QT_NO_TOOLTIP
        rescaleGlobalShiftCheckBox->setText(QApplication::translate("ScaleDialog", "Rescale Global shift", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScaleDialog: public Ui_ScaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEDLG_H
