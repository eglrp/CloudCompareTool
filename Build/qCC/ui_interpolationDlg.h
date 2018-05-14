/********************************************************************************
** Form generated from reading UI file 'interpolationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERPOLATIONDLG_H
#define UI_INTERPOLATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InterpolationDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *radiusDoubleSpinBox;
    QRadioButton *radiusRadioButton;
    QRadioButton *nnRadioButton;
    QRadioButton *knnRadioButton;
    QSpinBox *knnSpinBox;
    QGroupBox *algoGroupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *medianRadioButton;
    QRadioButton *averageRadioButton;
    QRadioButton *normalDistribRadioButton;
    QFrame *kernelFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QDoubleSpinBox *kernelDoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InterpolationDlg)
    {
        if (InterpolationDlg->objectName().isEmpty())
            InterpolationDlg->setObjectName(QStringLiteral("InterpolationDlg"));
        InterpolationDlg->resize(400, 260);
        verticalLayout = new QVBoxLayout(InterpolationDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(InterpolationDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radiusDoubleSpinBox = new QDoubleSpinBox(groupBox);
        radiusDoubleSpinBox->setObjectName(QStringLiteral("radiusDoubleSpinBox"));
        radiusDoubleSpinBox->setDecimals(6);
        radiusDoubleSpinBox->setMaximum(1e+9);

        gridLayout->addWidget(radiusDoubleSpinBox, 1, 2, 1, 1);

        radiusRadioButton = new QRadioButton(groupBox);
        radiusRadioButton->setObjectName(QStringLiteral("radiusRadioButton"));
        radiusRadioButton->setChecked(true);

        gridLayout->addWidget(radiusRadioButton, 0, 2, 1, 1);

        nnRadioButton = new QRadioButton(groupBox);
        nnRadioButton->setObjectName(QStringLiteral("nnRadioButton"));

        gridLayout->addWidget(nnRadioButton, 0, 0, 1, 1);

        knnRadioButton = new QRadioButton(groupBox);
        knnRadioButton->setObjectName(QStringLiteral("knnRadioButton"));

        gridLayout->addWidget(knnRadioButton, 0, 1, 1, 1);

        knnSpinBox = new QSpinBox(groupBox);
        knnSpinBox->setObjectName(QStringLiteral("knnSpinBox"));
        knnSpinBox->setEnabled(false);
        knnSpinBox->setMinimum(3);
        knnSpinBox->setMaximum(1000000000);
        knnSpinBox->setValue(8);

        gridLayout->addWidget(knnSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        algoGroupBox = new QGroupBox(InterpolationDlg);
        algoGroupBox->setObjectName(QStringLiteral("algoGroupBox"));
        gridLayout_2 = new QGridLayout(algoGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        medianRadioButton = new QRadioButton(algoGroupBox);
        medianRadioButton->setObjectName(QStringLiteral("medianRadioButton"));
        medianRadioButton->setChecked(true);

        gridLayout_2->addWidget(medianRadioButton, 1, 0, 1, 1);

        averageRadioButton = new QRadioButton(algoGroupBox);
        averageRadioButton->setObjectName(QStringLiteral("averageRadioButton"));

        gridLayout_2->addWidget(averageRadioButton, 0, 0, 1, 1);

        normalDistribRadioButton = new QRadioButton(algoGroupBox);
        normalDistribRadioButton->setObjectName(QStringLiteral("normalDistribRadioButton"));

        gridLayout_2->addWidget(normalDistribRadioButton, 2, 0, 1, 1);

        kernelFrame = new QFrame(algoGroupBox);
        kernelFrame->setObjectName(QStringLiteral("kernelFrame"));
        kernelFrame->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kernelFrame->sizePolicy().hasHeightForWidth());
        kernelFrame->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(kernelFrame);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(kernelFrame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        kernelDoubleSpinBox = new QDoubleSpinBox(kernelFrame);
        kernelDoubleSpinBox->setObjectName(QStringLiteral("kernelDoubleSpinBox"));
        kernelDoubleSpinBox->setDecimals(6);
        kernelDoubleSpinBox->setMaximum(1e+9);
        kernelDoubleSpinBox->setValue(1);

        horizontalLayout->addWidget(kernelDoubleSpinBox);


        gridLayout_2->addWidget(kernelFrame, 2, 1, 1, 1);


        verticalLayout->addWidget(algoGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(InterpolationDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InterpolationDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), InterpolationDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InterpolationDlg, SLOT(reject()));
        QObject::connect(knnRadioButton, SIGNAL(toggled(bool)), knnSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(radiusRadioButton, SIGNAL(toggled(bool)), radiusDoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(normalDistribRadioButton, SIGNAL(toggled(bool)), kernelFrame, SLOT(setEnabled(bool)));
        QObject::connect(nnRadioButton, SIGNAL(toggled(bool)), algoGroupBox, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(InterpolationDlg);
    } // setupUi

    void retranslateUi(QDialog *InterpolationDlg)
    {
        InterpolationDlg->setWindowTitle(QApplication::translate("InterpolationDlg", "Interpolation", nullptr));
        groupBox->setTitle(QApplication::translate("InterpolationDlg", "Neighbors extraction", nullptr));
#ifndef QT_NO_TOOLTIP
        radiusDoubleSpinBox->setToolTip(QApplication::translate("InterpolationDlg", "Radius of the sphere inside which neighbors will be extracted", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        radiusRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Extracts the neighbors inside a sphere", nullptr));
#endif // QT_NO_TOOLTIP
        radiusRadioButton->setText(QApplication::translate("InterpolationDlg", "Radius (Sphere)", nullptr));
#ifndef QT_NO_TOOLTIP
        nnRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Use only the nearest neighbor (fast)", nullptr));
#endif // QT_NO_TOOLTIP
        nnRadioButton->setText(QApplication::translate("InterpolationDlg", "Nearest neighbor", nullptr));
#ifndef QT_NO_TOOLTIP
        knnRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Use the 'k' nearest neighbors\n"
"(faster than 'radius' based search, but more approximate)", nullptr));
#endif // QT_NO_TOOLTIP
        knnRadioButton->setText(QApplication::translate("InterpolationDlg", "Nearest neighbors", nullptr));
#ifndef QT_NO_TOOLTIP
        knnSpinBox->setToolTip(QApplication::translate("InterpolationDlg", "Number of neighbors to extract", nullptr));
#endif // QT_NO_TOOLTIP
        algoGroupBox->setTitle(QApplication::translate("InterpolationDlg", "Interpolation algorithm", nullptr));
#ifndef QT_NO_TOOLTIP
        medianRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Keep the median of the neighbors SF values", nullptr));
#endif // QT_NO_TOOLTIP
        medianRadioButton->setText(QApplication::translate("InterpolationDlg", "Median", nullptr));
#ifndef QT_NO_TOOLTIP
        averageRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Keep the average of the neighbors SF values", nullptr));
#endif // QT_NO_TOOLTIP
        averageRadioButton->setText(QApplication::translate("InterpolationDlg", "Average", nullptr));
#ifndef QT_NO_TOOLTIP
        normalDistribRadioButton->setToolTip(QApplication::translate("InterpolationDlg", "Compute a weighted average of the neighbors SF values\n"
"(the weights will follow a Normal distribution)", nullptr));
#endif // QT_NO_TOOLTIP
        normalDistribRadioButton->setText(QApplication::translate("InterpolationDlg", "Normal distribution", nullptr));
        label->setText(QApplication::translate("InterpolationDlg", "sigma", nullptr));
#ifndef QT_NO_TOOLTIP
        kernelDoubleSpinBox->setToolTip(QApplication::translate("InterpolationDlg", "Kernel of the Normal distribution", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class InterpolationDlg: public Ui_InterpolationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERPOLATIONDLG_H
