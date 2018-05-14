/********************************************************************************
** Form generated from reading UI file 'volumeCalcDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMECALCDLG_H
#define UI_VOLUMECALCDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeCalcDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groundGroupBox;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QComboBox *groundComboBox;
    QComboBox *fillGroundEmptyCellsComboBox;
    QLabel *label_10;
    QDoubleSpinBox *groundEmptyValueDoubleSpinBox;
    QFrame *swapButtonFrame;
    QHBoxLayout *horizontalLayout;
    QToolButton *swapToolButton;
    QGroupBox *ceilGroupBox;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QComboBox *ceilComboBox;
    QLabel *label_6;
    QComboBox *fillCeilEmptyCellsComboBox;
    QDoubleSpinBox *ceilEmptyValueDoubleSpinBox;
    QGroupBox *gridGroupBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *gridParamsWidget;
    QFormLayout *formLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *gridStepDoubleSpinBox;
    QToolButton *editGridToolButton;
    QLabel *label_4;
    QLabel *gridWidthLabel;
    QLabel *label_9;
    QComboBox *projDimComboBox;
    QLabel *label_8;
    QComboBox *heightProjectionComboBox;
    QPushButton *updatePushButton;
    QGroupBox *resultGroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *spareseWarningLabel;
    QPlainTextEdit *reportPlainTextEdit;
    QPushButton *clipboardPushButton;
    QPushButton *exportGridPushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *precisionSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QFrame *mapFrame;

    void setupUi(QDialog *VolumeCalcDialog)
    {
        if (VolumeCalcDialog->objectName().isEmpty())
            VolumeCalcDialog->setObjectName(QStringLiteral("VolumeCalcDialog"));
        VolumeCalcDialog->resize(1000, 869);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VolumeCalcDialog->sizePolicy().hasHeightForWidth());
        VolumeCalcDialog->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(VolumeCalcDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        leftFrame = new QFrame(VolumeCalcDialog);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftFrame->sizePolicy().hasHeightForWidth());
        leftFrame->setSizePolicy(sizePolicy1);
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(leftFrame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groundGroupBox = new QGroupBox(leftFrame);
        groundGroupBox->setObjectName(QStringLiteral("groundGroupBox"));
        formLayout_2 = new QFormLayout(groundGroupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_7 = new QLabel(groundGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        groundComboBox = new QComboBox(groundGroupBox);
        groundComboBox->setObjectName(QStringLiteral("groundComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, groundComboBox);

        fillGroundEmptyCellsComboBox = new QComboBox(groundGroupBox);
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->addItem(QString());
        fillGroundEmptyCellsComboBox->setObjectName(QStringLiteral("fillGroundEmptyCellsComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, fillGroundEmptyCellsComboBox);

        label_10 = new QLabel(groundGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        groundEmptyValueDoubleSpinBox = new QDoubleSpinBox(groundGroupBox);
        groundEmptyValueDoubleSpinBox->setObjectName(QStringLiteral("groundEmptyValueDoubleSpinBox"));
        groundEmptyValueDoubleSpinBox->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groundEmptyValueDoubleSpinBox->sizePolicy().hasHeightForWidth());
        groundEmptyValueDoubleSpinBox->setSizePolicy(sizePolicy2);
        groundEmptyValueDoubleSpinBox->setDecimals(6);
        groundEmptyValueDoubleSpinBox->setMinimum(-1e+9);
        groundEmptyValueDoubleSpinBox->setMaximum(1e+9);
        groundEmptyValueDoubleSpinBox->setValue(0);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, groundEmptyValueDoubleSpinBox);


        verticalLayout_2->addWidget(groundGroupBox);

        swapButtonFrame = new QFrame(leftFrame);
        swapButtonFrame->setObjectName(QStringLiteral("swapButtonFrame"));
        swapButtonFrame->setFrameShape(QFrame::StyledPanel);
        swapButtonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(swapButtonFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        swapToolButton = new QToolButton(swapButtonFrame);
        swapToolButton->setObjectName(QStringLiteral("swapToolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccSwapUpDown.png"), QSize(), QIcon::Normal, QIcon::Off);
        swapToolButton->setIcon(icon);
        swapToolButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(swapToolButton);


        verticalLayout_2->addWidget(swapButtonFrame);

        ceilGroupBox = new QGroupBox(leftFrame);
        ceilGroupBox->setObjectName(QStringLiteral("ceilGroupBox"));
        formLayout_3 = new QFormLayout(ceilGroupBox);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_3 = new QLabel(ceilGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        ceilComboBox = new QComboBox(ceilGroupBox);
        ceilComboBox->setObjectName(QStringLiteral("ceilComboBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, ceilComboBox);

        label_6 = new QLabel(ceilGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        fillCeilEmptyCellsComboBox = new QComboBox(ceilGroupBox);
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->addItem(QString());
        fillCeilEmptyCellsComboBox->setObjectName(QStringLiteral("fillCeilEmptyCellsComboBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, fillCeilEmptyCellsComboBox);

        ceilEmptyValueDoubleSpinBox = new QDoubleSpinBox(ceilGroupBox);
        ceilEmptyValueDoubleSpinBox->setObjectName(QStringLiteral("ceilEmptyValueDoubleSpinBox"));
        ceilEmptyValueDoubleSpinBox->setEnabled(false);
        sizePolicy2.setHeightForWidth(ceilEmptyValueDoubleSpinBox->sizePolicy().hasHeightForWidth());
        ceilEmptyValueDoubleSpinBox->setSizePolicy(sizePolicy2);
        ceilEmptyValueDoubleSpinBox->setDecimals(6);
        ceilEmptyValueDoubleSpinBox->setMinimum(-1e+9);
        ceilEmptyValueDoubleSpinBox->setMaximum(1e+9);
        ceilEmptyValueDoubleSpinBox->setValue(0);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ceilEmptyValueDoubleSpinBox);


        verticalLayout_2->addWidget(ceilGroupBox);

        gridGroupBox = new QGroupBox(leftFrame);
        gridGroupBox->setObjectName(QStringLiteral("gridGroupBox"));
        verticalLayout_3 = new QVBoxLayout(gridGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridParamsWidget = new QWidget(gridGroupBox);
        gridParamsWidget->setObjectName(QStringLiteral("gridParamsWidget"));
        formLayout_4 = new QFormLayout(gridParamsWidget);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(2, 2, 2, 2);
        label_2 = new QLabel(gridParamsWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 2, -1);
        gridStepDoubleSpinBox = new QDoubleSpinBox(gridParamsWidget);
        gridStepDoubleSpinBox->setObjectName(QStringLiteral("gridStepDoubleSpinBox"));
        gridStepDoubleSpinBox->setDecimals(6);
        gridStepDoubleSpinBox->setMinimum(0.001);
        gridStepDoubleSpinBox->setMaximum(1000);
        gridStepDoubleSpinBox->setSingleStep(0.001);
        gridStepDoubleSpinBox->setValue(1);

        horizontalLayout_4->addWidget(gridStepDoubleSpinBox);

        editGridToolButton = new QToolButton(gridParamsWidget);
        editGridToolButton->setObjectName(QStringLiteral("editGridToolButton"));

        horizontalLayout_4->addWidget(editGridToolButton);


        formLayout_4->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        label_4 = new QLabel(gridParamsWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_4);

        gridWidthLabel = new QLabel(gridParamsWidget);
        gridWidthLabel->setObjectName(QStringLiteral("gridWidthLabel"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, gridWidthLabel);

        label_9 = new QLabel(gridParamsWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_9);

        projDimComboBox = new QComboBox(gridParamsWidget);
        projDimComboBox->addItem(QString());
        projDimComboBox->addItem(QString());
        projDimComboBox->addItem(QString());
        projDimComboBox->setObjectName(QStringLiteral("projDimComboBox"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, projDimComboBox);

        label_8 = new QLabel(gridParamsWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_8);

        heightProjectionComboBox = new QComboBox(gridParamsWidget);
        heightProjectionComboBox->addItem(QString());
        heightProjectionComboBox->addItem(QString());
        heightProjectionComboBox->addItem(QString());
        heightProjectionComboBox->setObjectName(QStringLiteral("heightProjectionComboBox"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, heightProjectionComboBox);


        verticalLayout_3->addWidget(gridParamsWidget);

        updatePushButton = new QPushButton(gridGroupBox);
        updatePushButton->setObjectName(QStringLiteral("updatePushButton"));
        updatePushButton->setStyleSheet(QStringLiteral("color: white; background-color:red;"));

        verticalLayout_3->addWidget(updatePushButton);


        verticalLayout_2->addWidget(gridGroupBox);

        resultGroupBox = new QGroupBox(leftFrame);
        resultGroupBox->setObjectName(QStringLiteral("resultGroupBox"));
        verticalLayout = new QVBoxLayout(resultGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        spareseWarningLabel = new QLabel(resultGroupBox);
        spareseWarningLabel->setObjectName(QStringLiteral("spareseWarningLabel"));
        spareseWarningLabel->setStyleSheet(QStringLiteral("color:red;"));
        spareseWarningLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(spareseWarningLabel);

        reportPlainTextEdit = new QPlainTextEdit(resultGroupBox);
        reportPlainTextEdit->setObjectName(QStringLiteral("reportPlainTextEdit"));
        reportPlainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(reportPlainTextEdit);

        clipboardPushButton = new QPushButton(resultGroupBox);
        clipboardPushButton->setObjectName(QStringLiteral("clipboardPushButton"));
        clipboardPushButton->setEnabled(false);

        verticalLayout->addWidget(clipboardPushButton);

        exportGridPushButton = new QPushButton(resultGroupBox);
        exportGridPushButton->setObjectName(QStringLiteral("exportGridPushButton"));
        exportGridPushButton->setEnabled(false);

        verticalLayout->addWidget(exportGridPushButton);

        widget = new QWidget(resultGroupBox);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        precisionSpinBox = new QSpinBox(widget);
        precisionSpinBox->setObjectName(QStringLiteral("precisionSpinBox"));
        precisionSpinBox->setMaximum(12);
        precisionSpinBox->setValue(3);

        horizontalLayout_2->addWidget(precisionSpinBox);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addWidget(resultGroupBox);

        verticalSpacer = new QSpacerItem(20, 56, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(leftFrame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout_2->addWidget(buttonBox);


        horizontalLayout_3->addWidget(leftFrame);

        mapFrame = new QFrame(VolumeCalcDialog);
        mapFrame->setObjectName(QStringLiteral("mapFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mapFrame->sizePolicy().hasHeightForWidth());
        mapFrame->setSizePolicy(sizePolicy3);
        mapFrame->setMinimumSize(QSize(256, 256));
        mapFrame->setFrameShape(QFrame::StyledPanel);
        mapFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(mapFrame);


        retranslateUi(VolumeCalcDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VolumeCalcDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VolumeCalcDialog, SLOT(reject()));

        projDimComboBox->setCurrentIndex(2);
        heightProjectionComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VolumeCalcDialog);
    } // setupUi

    void retranslateUi(QDialog *VolumeCalcDialog)
    {
        VolumeCalcDialog->setWindowTitle(QApplication::translate("VolumeCalcDialog", "Volume calculation", nullptr));
        groundGroupBox->setTitle(QApplication::translate("VolumeCalcDialog", "Ground / Before", nullptr));
        label_7->setText(QApplication::translate("VolumeCalcDialog", "Source", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(0, QApplication::translate("VolumeCalcDialog", "leave empty", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(1, QApplication::translate("VolumeCalcDialog", "minimum height", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(2, QApplication::translate("VolumeCalcDialog", "average height", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(3, QApplication::translate("VolumeCalcDialog", "maximum height", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(4, QApplication::translate("VolumeCalcDialog", "user specified value", nullptr));
        fillGroundEmptyCellsComboBox->setItemText(5, QApplication::translate("VolumeCalcDialog", "interpolate", nullptr));

#ifndef QT_NO_TOOLTIP
        fillGroundEmptyCellsComboBox->setToolTip(QApplication::translate("VolumeCalcDialog", "choose the value to fill the cells in which no point is projected : minimum value over the whole point cloud or average value (over the whole cloud also)", nullptr));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("VolumeCalcDialog", "Empty cells", nullptr));
#ifndef QT_NO_TOOLTIP
        groundEmptyValueDoubleSpinBox->setToolTip(QApplication::translate("VolumeCalcDialog", "Custom value for empty cells", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        swapToolButton->setToolTip(QApplication::translate("VolumeCalcDialog", "Swap", nullptr));
#endif // QT_NO_TOOLTIP
        swapToolButton->setText(QApplication::translate("VolumeCalcDialog", "swap", nullptr));
        ceilGroupBox->setTitle(QApplication::translate("VolumeCalcDialog", "Ceil / After", nullptr));
        label_3->setText(QApplication::translate("VolumeCalcDialog", "Source", nullptr));
        label_6->setText(QApplication::translate("VolumeCalcDialog", "Empty cells", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(0, QApplication::translate("VolumeCalcDialog", "leave empty", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(1, QApplication::translate("VolumeCalcDialog", "minimum height", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(2, QApplication::translate("VolumeCalcDialog", "average height", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(3, QApplication::translate("VolumeCalcDialog", "maximum height", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(4, QApplication::translate("VolumeCalcDialog", "user specified value", nullptr));
        fillCeilEmptyCellsComboBox->setItemText(5, QApplication::translate("VolumeCalcDialog", "interpolate", nullptr));

#ifndef QT_NO_TOOLTIP
        fillCeilEmptyCellsComboBox->setToolTip(QApplication::translate("VolumeCalcDialog", "choose the value to fill the cells in which no point is projected : minimum value over the whole point cloud or average value (over the whole cloud also)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ceilEmptyValueDoubleSpinBox->setToolTip(QApplication::translate("VolumeCalcDialog", "Custom value for empty cells", nullptr));
#endif // QT_NO_TOOLTIP
        gridGroupBox->setTitle(QApplication::translate("VolumeCalcDialog", "Grid", nullptr));
        label_2->setText(QApplication::translate("VolumeCalcDialog", "step", nullptr));
#ifndef QT_NO_TOOLTIP
        gridStepDoubleSpinBox->setToolTip(QApplication::translate("VolumeCalcDialog", "size of step of the grid generated (in the same units as the coordinates of the point cloud)", nullptr));
#endif // QT_NO_TOOLTIP
        editGridToolButton->setText(QApplication::translate("VolumeCalcDialog", "Edit grid", nullptr));
        label_4->setText(QApplication::translate("VolumeCalcDialog", "size", nullptr));
#ifndef QT_NO_TOOLTIP
        gridWidthLabel->setToolTip(QApplication::translate("VolumeCalcDialog", "Grid size corresponding to the current step / boundaries", nullptr));
#endif // QT_NO_TOOLTIP
        gridWidthLabel->setText(QApplication::translate("VolumeCalcDialog", "640 x 480", nullptr));
        label_9->setText(QApplication::translate("VolumeCalcDialog", "projection dir.", nullptr));
        projDimComboBox->setItemText(0, QApplication::translate("VolumeCalcDialog", "X", nullptr));
        projDimComboBox->setItemText(1, QApplication::translate("VolumeCalcDialog", "Y", nullptr));
        projDimComboBox->setItemText(2, QApplication::translate("VolumeCalcDialog", "Z", nullptr));

#ifndef QT_NO_TOOLTIP
        projDimComboBox->setToolTip(QApplication::translate("VolumeCalcDialog", "Projection direction (X, Y or Z)", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("VolumeCalcDialog", "cell height", nullptr));
        heightProjectionComboBox->setItemText(0, QApplication::translate("VolumeCalcDialog", "minimum height", nullptr));
        heightProjectionComboBox->setItemText(1, QApplication::translate("VolumeCalcDialog", "average height", nullptr));
        heightProjectionComboBox->setItemText(2, QApplication::translate("VolumeCalcDialog", "maximum height", nullptr));

#ifndef QT_NO_TOOLTIP
        heightProjectionComboBox->setToolTip(QApplication::translate("VolumeCalcDialog", "Per-cell height computation method:\n"
" - minimum = lowest point in the cell\n"
" - average = mean height of all points inside the cell\n"
" - maximum = highest point in the cell", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        updatePushButton->setToolTip(QApplication::translate("VolumeCalcDialog", "Update the grid / display / measurements", nullptr));
#endif // QT_NO_TOOLTIP
        updatePushButton->setText(QApplication::translate("VolumeCalcDialog", "Update", nullptr));
        resultGroupBox->setTitle(QApplication::translate("VolumeCalcDialog", "Results", nullptr));
        spareseWarningLabel->setText(QApplication::translate("VolumeCalcDialog", "At least one of the cloud is sparse!\n"
"You should fill the empty cells...", nullptr));
        clipboardPushButton->setText(QApplication::translate("VolumeCalcDialog", "Copy to clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        exportGridPushButton->setToolTip(QApplication::translate("VolumeCalcDialog", "Export the grid as a point cloud\n"
"(warning, the points heights will be the difference of altitude!)", nullptr));
#endif // QT_NO_TOOLTIP
        exportGridPushButton->setText(QApplication::translate("VolumeCalcDialog", "Export grid as a cloud", nullptr));
        label->setText(QApplication::translate("VolumeCalcDialog", "Num. precision", nullptr));
#ifndef QT_NO_TOOLTIP
        precisionSpinBox->setToolTip(QApplication::translate("VolumeCalcDialog", "Numerical precision (output measurements, etc.)", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class VolumeCalcDialog: public Ui_VolumeCalcDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMECALCDLG_H
