/********************************************************************************
** Form generated from reading UI file 'stereoModeDlgV2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOMODEDLGV2_H
#define UI_STEREOMODEDLGV2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StereoModeDialogV2
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *glassTypeComboBox;
    QTextEdit *warningTextEdit;
    QGroupBox *paramsGroupBox;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QDoubleSpinBox *eyeSepDoubleSpinBox;
    QLabel *label_3;
    QLabel *label_2;
    QCheckBox *autoFocalCheckBox;
    QDoubleSpinBox *focalDoubleSpinBox;
    QLabel *autoFocusLabel;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StereoModeDialogV2)
    {
        if (StereoModeDialogV2->objectName().isEmpty())
            StereoModeDialogV2->setObjectName(QStringLiteral("StereoModeDialogV2"));
        StereoModeDialogV2->resize(472, 325);
        verticalLayout_2 = new QVBoxLayout(StereoModeDialogV2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(StereoModeDialogV2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        glassTypeComboBox = new QComboBox(StereoModeDialogV2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccStereo.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/nvidia.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/oculus.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon2, QString());
        glassTypeComboBox->setObjectName(QStringLiteral("glassTypeComboBox"));

        horizontalLayout->addWidget(glassTypeComboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        warningTextEdit = new QTextEdit(StereoModeDialogV2);
        warningTextEdit->setObjectName(QStringLiteral("warningTextEdit"));

        verticalLayout_2->addWidget(warningTextEdit);

        paramsGroupBox = new QGroupBox(StereoModeDialogV2);
        paramsGroupBox->setObjectName(QStringLiteral("paramsGroupBox"));
        verticalLayout = new QVBoxLayout(paramsGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(paramsGroupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        eyeSepDoubleSpinBox = new QDoubleSpinBox(frame);
        eyeSepDoubleSpinBox->setObjectName(QStringLiteral("eyeSepDoubleSpinBox"));
        eyeSepDoubleSpinBox->setDecimals(1);
        eyeSepDoubleSpinBox->setMinimum(0.1);
        eyeSepDoubleSpinBox->setSingleStep(0.1);
        eyeSepDoubleSpinBox->setValue(3.3);

        gridLayout->addWidget(eyeSepDoubleSpinBox, 0, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        autoFocalCheckBox = new QCheckBox(frame);
        autoFocalCheckBox->setObjectName(QStringLiteral("autoFocalCheckBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(autoFocalCheckBox->sizePolicy().hasHeightForWidth());
        autoFocalCheckBox->setSizePolicy(sizePolicy);
        autoFocalCheckBox->setChecked(true);

        gridLayout->addWidget(autoFocalCheckBox, 1, 2, 1, 1);

        focalDoubleSpinBox = new QDoubleSpinBox(frame);
        focalDoubleSpinBox->setObjectName(QStringLiteral("focalDoubleSpinBox"));
        focalDoubleSpinBox->setEnabled(false);
        focalDoubleSpinBox->setDecimals(3);
        focalDoubleSpinBox->setMinimum(0);
        focalDoubleSpinBox->setMaximum(1e+6);
        focalDoubleSpinBox->setValue(0.5);

        gridLayout->addWidget(focalDoubleSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(frame);

        autoFocusLabel = new QLabel(paramsGroupBox);
        autoFocusLabel->setObjectName(QStringLiteral("autoFocusLabel"));
        QFont font;
        font.setItalic(true);
        autoFocusLabel->setFont(font);
        autoFocusLabel->setStyleSheet(QStringLiteral("color: blue;"));

        verticalLayout->addWidget(autoFocusLabel);


        verticalLayout_2->addWidget(paramsGroupBox);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(StereoModeDialogV2);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(StereoModeDialogV2);
        QObject::connect(buttonBox, SIGNAL(accepted()), StereoModeDialogV2, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StereoModeDialogV2, SLOT(reject()));
        QObject::connect(autoFocalCheckBox, SIGNAL(toggled(bool)), focalDoubleSpinBox, SLOT(setDisabled(bool)));
        QObject::connect(autoFocalCheckBox, SIGNAL(toggled(bool)), autoFocusLabel, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(StereoModeDialogV2);
    } // setupUi

    void retranslateUi(QDialog *StereoModeDialogV2)
    {
        StereoModeDialogV2->setWindowTitle(QApplication::translate("StereoModeDialogV2", "Stereo mode", nullptr));
        label->setText(QApplication::translate("StereoModeDialogV2", "Glasses", nullptr));
        glassTypeComboBox->setItemText(0, QApplication::translate("StereoModeDialogV2", "Red-Blue", nullptr));
        glassTypeComboBox->setItemText(1, QApplication::translate("StereoModeDialogV2", "Blue-Red", nullptr));
        glassTypeComboBox->setItemText(2, QApplication::translate("StereoModeDialogV2", "Red-Cyan", nullptr));
        glassTypeComboBox->setItemText(3, QApplication::translate("StereoModeDialogV2", "Cyan-Red", nullptr));
        glassTypeComboBox->setItemText(4, QApplication::translate("StereoModeDialogV2", "NVidia Vision", nullptr));
        glassTypeComboBox->setItemText(5, QApplication::translate("StereoModeDialogV2", "Oculus", nullptr));

        warningTextEdit->setHtml(QApplication::translate("StereoModeDialogV2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">To make this mode work properly make sure that:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">- the NVidia Vision IR emitter is plugged and enabled (dim green light)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size"
                        ":8pt;\">- 3D stereo mode is activated in the NVidia Control Pannel</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">- the screen frequency is set to 120Hz</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">- the glasses are switched on</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Note: the current 3D view will be automatically displayed in exclusive full screen mode -"
                        " press F11 to quit this mode</span></p></body></html>", nullptr));
        paramsGroupBox->setTitle(QApplication::translate("StereoModeDialogV2", "Parameters", nullptr));
        eyeSepDoubleSpinBox->setSuffix(QApplication::translate("StereoModeDialogV2", "%", nullptr));
        label_3->setText(QApplication::translate("StereoModeDialogV2", "Eyes separation", nullptr));
        label_2->setText(QApplication::translate("StereoModeDialogV2", "Focal distance", nullptr));
        autoFocalCheckBox->setText(QApplication::translate("StereoModeDialogV2", "auto", nullptr));
        autoFocusLabel->setText(QApplication::translate("StereoModeDialogV2", "Note: the focus will depend on the distance to the rotation center", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoModeDialogV2: public Ui_StereoModeDialogV2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOMODEDLGV2_H
