/********************************************************************************
** Form generated from reading UI file 'saveLASFileDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVELASFILEDLG_H
#define UI_SAVELASFILEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SaveLASFileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *bestRadioButton;
    QLabel *bestAccuracyLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *origRadioButton;
    QLabel *origAccuracyLabel;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *customRadioButton;
    QDoubleSpinBox *customScaleDoubleSpinBox;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QLabel *label_5;
    QGroupBox *extraFieldGroupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *evlrListWidget;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SaveLASFileDialog)
    {
        if (SaveLASFileDialog->objectName().isEmpty())
            SaveLASFileDialog->setObjectName(QStringLiteral("SaveLASFileDialog"));
        SaveLASFileDialog->resize(380, 270);
        verticalLayout = new QVBoxLayout(SaveLASFileDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(SaveLASFileDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        bestRadioButton = new QRadioButton(SaveLASFileDialog);
        bestRadioButton->setObjectName(QStringLiteral("bestRadioButton"));

        horizontalLayout_4->addWidget(bestRadioButton);

        bestAccuracyLabel = new QLabel(SaveLASFileDialog);
        bestAccuracyLabel->setObjectName(QStringLiteral("bestAccuracyLabel"));

        horizontalLayout_4->addWidget(bestAccuracyLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(SaveLASFileDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setItalic(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        origRadioButton = new QRadioButton(SaveLASFileDialog);
        origRadioButton->setObjectName(QStringLiteral("origRadioButton"));
        origRadioButton->setCheckable(true);
        origRadioButton->setChecked(true);

        horizontalLayout_5->addWidget(origRadioButton);

        origAccuracyLabel = new QLabel(SaveLASFileDialog);
        origAccuracyLabel->setObjectName(QStringLiteral("origAccuracyLabel"));

        horizontalLayout_5->addWidget(origAccuracyLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        label_4 = new QLabel(SaveLASFileDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        customRadioButton = new QRadioButton(SaveLASFileDialog);
        customRadioButton->setObjectName(QStringLiteral("customRadioButton"));

        horizontalLayout_6->addWidget(customRadioButton);

        customScaleDoubleSpinBox = new QDoubleSpinBox(SaveLASFileDialog);
        customScaleDoubleSpinBox->setObjectName(QStringLiteral("customScaleDoubleSpinBox"));
        customScaleDoubleSpinBox->setEnabled(false);
        customScaleDoubleSpinBox->setDecimals(8);
        customScaleDoubleSpinBox->setMinimum(0);
        customScaleDoubleSpinBox->setMaximum(1);
        customScaleDoubleSpinBox->setSingleStep(0.001);
        customScaleDoubleSpinBox->setValue(0.001);

        horizontalLayout_6->addWidget(customScaleDoubleSpinBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_6);

        label_3 = new QLabel(SaveLASFileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(SaveLASFileDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: red;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);

        extraFieldGroupBox = new QGroupBox(SaveLASFileDialog);
        extraFieldGroupBox->setObjectName(QStringLiteral("extraFieldGroupBox"));
        extraFieldGroupBox->setCheckable(true);
        extraFieldGroupBox->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(extraFieldGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        evlrListWidget = new QListWidget(extraFieldGroupBox);
        evlrListWidget->setObjectName(QStringLiteral("evlrListWidget"));
        evlrListWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(evlrListWidget);


        verticalLayout->addWidget(extraFieldGroupBox);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(SaveLASFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SaveLASFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SaveLASFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SaveLASFileDialog, SLOT(reject()));
        QObject::connect(customRadioButton, SIGNAL(toggled(bool)), customScaleDoubleSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(SaveLASFileDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveLASFileDialog)
    {
        SaveLASFileDialog->setWindowTitle(QApplication::translate("SaveLASFileDialog", "LAS/LAZ scale", nullptr));
        label->setText(QApplication::translate("SaveLASFileDialog", "Choose the output LAS/LAZ scale/resolution:", nullptr));
        bestRadioButton->setText(QApplication::translate("SaveLASFileDialog", "Highest resolution", nullptr));
        bestAccuracyLabel->setText(QApplication::translate("SaveLASFileDialog", "(0,0,0)", nullptr));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("SaveLASFileDialog", "Ensures optimal accuracy (up to 10^-7 absolute)", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SaveLASFileDialog", "will decrease LAZ compression efficiency", nullptr));
        origRadioButton->setText(QApplication::translate("SaveLASFileDialog", "Original resolution", nullptr));
        origAccuracyLabel->setText(QApplication::translate("SaveLASFileDialog", "(0,0,0)", nullptr));
        label_4->setText(QApplication::translate("SaveLASFileDialog", "might not preserve data accuracy\n"
"(especially if you have transformed the original data)", nullptr));
        customRadioButton->setText(QApplication::translate("SaveLASFileDialog", "Custom resolution", nullptr));
        label_3->setText(QApplication::translate("SaveLASFileDialog", "bigger scale = best LAZ compression = lower resolution(*)", nullptr));
        label_5->setText(QApplication::translate("SaveLASFileDialog", "(*) careful, if chosen too low coordinates will loose accuracy", nullptr));
        extraFieldGroupBox->setTitle(QApplication::translate("SaveLASFileDialog", "Save additional field(s)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveLASFileDialog: public Ui_SaveLASFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVELASFILEDLG_H
