/********************************************************************************
** Form generated from reading UI file 'planeEditDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANEEDITDLG_H
#define UI_PLANEEDITDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaneEditDlg
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *orientationTabWidget;
    QWidget *dipTab;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *dipDoubleSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *dipDirDoubleSpinBox;
    QCheckBox *upwardCheckBox;
    QWidget *normTab;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *nxDoubleSpinBox;
    QDoubleSpinBox *nyDoubleSpinBox;
    QDoubleSpinBox *nzDoubleSpinBox;
    QGroupBox *dimGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QDoubleSpinBox *wDoubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *hDoubleSpinBox;
    QGroupBox *centerGroupBox;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *cxAxisDoubleSpinBox;
    QToolButton *pickCenterToolButton;
    QDoubleSpinBox *cyAxisDoubleSpinBox;
    QDoubleSpinBox *czAxisDoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlaneEditDlg)
    {
        if (PlaneEditDlg->objectName().isEmpty())
            PlaneEditDlg->setObjectName(QStringLiteral("PlaneEditDlg"));
        PlaneEditDlg->resize(300, 380);
        verticalLayout = new QVBoxLayout(PlaneEditDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        orientationTabWidget = new QTabWidget(PlaneEditDlg);
        orientationTabWidget->setObjectName(QStringLiteral("orientationTabWidget"));
        dipTab = new QWidget();
        dipTab->setObjectName(QStringLiteral("dipTab"));
        gridLayout_4 = new QGridLayout(dipTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(dipTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        dipDoubleSpinBox = new QDoubleSpinBox(dipTab);
        dipDoubleSpinBox->setObjectName(QStringLiteral("dipDoubleSpinBox"));
        dipDoubleSpinBox->setDecimals(3);
        dipDoubleSpinBox->setMinimum(0);
        dipDoubleSpinBox->setMaximum(90);

        gridLayout_4->addWidget(dipDoubleSpinBox, 0, 1, 1, 1);

        label_4 = new QLabel(dipTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        dipDirDoubleSpinBox = new QDoubleSpinBox(dipTab);
        dipDirDoubleSpinBox->setObjectName(QStringLiteral("dipDirDoubleSpinBox"));
        dipDirDoubleSpinBox->setDecimals(4);
        dipDirDoubleSpinBox->setMinimum(0);
        dipDirDoubleSpinBox->setMaximum(360);

        gridLayout_4->addWidget(dipDirDoubleSpinBox, 1, 1, 1, 1);

        upwardCheckBox = new QCheckBox(dipTab);
        upwardCheckBox->setObjectName(QStringLiteral("upwardCheckBox"));
        upwardCheckBox->setChecked(true);

        gridLayout_4->addWidget(upwardCheckBox, 2, 0, 1, 1);

        orientationTabWidget->addTab(dipTab, QString());
        normTab = new QWidget();
        normTab->setObjectName(QStringLiteral("normTab"));
        verticalLayout_2 = new QVBoxLayout(normTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nxDoubleSpinBox = new QDoubleSpinBox(normTab);
        nxDoubleSpinBox->setObjectName(QStringLiteral("nxDoubleSpinBox"));
        nxDoubleSpinBox->setDecimals(6);
        nxDoubleSpinBox->setMinimum(-1e+6);
        nxDoubleSpinBox->setMaximum(1e+6);

        verticalLayout_2->addWidget(nxDoubleSpinBox);

        nyDoubleSpinBox = new QDoubleSpinBox(normTab);
        nyDoubleSpinBox->setObjectName(QStringLiteral("nyDoubleSpinBox"));
        nyDoubleSpinBox->setDecimals(6);
        nyDoubleSpinBox->setMinimum(-1e+6);
        nyDoubleSpinBox->setMaximum(1e+6);

        verticalLayout_2->addWidget(nyDoubleSpinBox);

        nzDoubleSpinBox = new QDoubleSpinBox(normTab);
        nzDoubleSpinBox->setObjectName(QStringLiteral("nzDoubleSpinBox"));
        nzDoubleSpinBox->setDecimals(6);
        nzDoubleSpinBox->setMinimum(-1e+6);
        nzDoubleSpinBox->setMaximum(1e+6);

        verticalLayout_2->addWidget(nzDoubleSpinBox);

        orientationTabWidget->addTab(normTab, QString());

        verticalLayout->addWidget(orientationTabWidget);

        dimGroupBox = new QGroupBox(PlaneEditDlg);
        dimGroupBox->setObjectName(QStringLiteral("dimGroupBox"));
        dimGroupBox->setFlat(true);
        gridLayout_2 = new QGridLayout(dimGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(dimGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        wDoubleSpinBox = new QDoubleSpinBox(dimGroupBox);
        wDoubleSpinBox->setObjectName(QStringLiteral("wDoubleSpinBox"));
        wDoubleSpinBox->setDecimals(6);
        wDoubleSpinBox->setMinimum(1e-6);
        wDoubleSpinBox->setMaximum(1e+6);
        wDoubleSpinBox->setValue(10);

        gridLayout_2->addWidget(wDoubleSpinBox, 0, 1, 1, 1);

        label_2 = new QLabel(dimGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        hDoubleSpinBox = new QDoubleSpinBox(dimGroupBox);
        hDoubleSpinBox->setObjectName(QStringLiteral("hDoubleSpinBox"));
        hDoubleSpinBox->setDecimals(6);
        hDoubleSpinBox->setMinimum(1e-6);
        hDoubleSpinBox->setMaximum(1e+6);
        hDoubleSpinBox->setValue(10);

        gridLayout_2->addWidget(hDoubleSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(dimGroupBox);

        centerGroupBox = new QGroupBox(PlaneEditDlg);
        centerGroupBox->setObjectName(QStringLiteral("centerGroupBox"));
        centerGroupBox->setFlat(true);
        gridLayout_3 = new QGridLayout(centerGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        cxAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        cxAxisDoubleSpinBox->setObjectName(QStringLiteral("cxAxisDoubleSpinBox"));
        cxAxisDoubleSpinBox->setDecimals(8);
        cxAxisDoubleSpinBox->setMinimum(-1e+9);
        cxAxisDoubleSpinBox->setMaximum(1e+9);

        gridLayout_3->addWidget(cxAxisDoubleSpinBox, 0, 1, 1, 1);

        pickCenterToolButton = new QToolButton(centerGroupBox);
        pickCenterToolButton->setObjectName(QStringLiteral("pickCenterToolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccPointPicking.png"), QSize(), QIcon::Normal, QIcon::Off);
        pickCenterToolButton->setIcon(icon);
        pickCenterToolButton->setCheckable(true);

        gridLayout_3->addWidget(pickCenterToolButton, 1, 0, 1, 1);

        cyAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        cyAxisDoubleSpinBox->setObjectName(QStringLiteral("cyAxisDoubleSpinBox"));
        cyAxisDoubleSpinBox->setDecimals(8);
        cyAxisDoubleSpinBox->setMinimum(-1e+9);
        cyAxisDoubleSpinBox->setMaximum(1e+9);

        gridLayout_3->addWidget(cyAxisDoubleSpinBox, 1, 1, 1, 1);

        czAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        czAxisDoubleSpinBox->setObjectName(QStringLiteral("czAxisDoubleSpinBox"));
        czAxisDoubleSpinBox->setDecimals(8);
        czAxisDoubleSpinBox->setMinimum(-1e+9);
        czAxisDoubleSpinBox->setMaximum(1e+9);

        gridLayout_3->addWidget(czAxisDoubleSpinBox, 2, 1, 1, 1);


        verticalLayout->addWidget(centerGroupBox);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(PlaneEditDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PlaneEditDlg);
        QObject::connect(buttonBox, SIGNAL(rejected()), PlaneEditDlg, SLOT(reject()));

        orientationTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PlaneEditDlg);
    } // setupUi

    void retranslateUi(QDialog *PlaneEditDlg)
    {
        PlaneEditDlg->setWindowTitle(QApplication::translate("PlaneEditDlg", "Plane properties", nullptr));
        label_3->setText(QApplication::translate("PlaneEditDlg", "dip", nullptr));
        dipDoubleSpinBox->setSuffix(QApplication::translate("PlaneEditDlg", " deg.", nullptr));
        label_4->setText(QApplication::translate("PlaneEditDlg", "dip direction", nullptr));
        dipDirDoubleSpinBox->setSuffix(QApplication::translate("PlaneEditDlg", " deg.", nullptr));
#ifndef QT_NO_TOOLTIP
        upwardCheckBox->setToolTip(QApplication::translate("PlaneEditDlg", "Whether the plane normal should point upward (Z+) or backward (Z-)", nullptr));
#endif // QT_NO_TOOLTIP
        upwardCheckBox->setText(QApplication::translate("PlaneEditDlg", "upward", nullptr));
        orientationTabWidget->setTabText(orientationTabWidget->indexOf(dipTab), QApplication::translate("PlaneEditDlg", "Dip / dip direction", nullptr));
        nxDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "Nx = ", nullptr));
        nyDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "Ny = ", nullptr));
        nzDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "Nz = ", nullptr));
        orientationTabWidget->setTabText(orientationTabWidget->indexOf(normTab), QApplication::translate("PlaneEditDlg", "Normal", nullptr));
        dimGroupBox->setTitle(QApplication::translate("PlaneEditDlg", "Dimensions", nullptr));
        label->setText(QApplication::translate("PlaneEditDlg", "width", nullptr));
#ifndef QT_NO_TOOLTIP
        wDoubleSpinBox->setToolTip(QApplication::translate("PlaneEditDlg", "Plane width", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("PlaneEditDlg", "height", nullptr));
#ifndef QT_NO_TOOLTIP
        hDoubleSpinBox->setToolTip(QApplication::translate("PlaneEditDlg", "Plane height", nullptr));
#endif // QT_NO_TOOLTIP
        centerGroupBox->setTitle(QApplication::translate("PlaneEditDlg", "Center", nullptr));
        cxAxisDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "X:", nullptr));
#ifndef QT_NO_TOOLTIP
        pickCenterToolButton->setToolTip(QApplication::translate("PlaneEditDlg", "Pick the plane center (click again to cancel)", nullptr));
#endif // QT_NO_TOOLTIP
        cyAxisDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "Y:", nullptr));
        czAxisDoubleSpinBox->setPrefix(QApplication::translate("PlaneEditDlg", "Z:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneEditDlg: public Ui_PlaneEditDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEEDITDLG_H
