/********************************************************************************
** Form generated from reading UI file 'matrixDisplayDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXDISPLAYDLG_H
#define UI_MATRIXDISPLAYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatrixDisplayDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *Export;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTextEdit *maxTextEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *axisLabel;
    QLabel *label_2;
    QLineEdit *angleLabel;
    QLabel *label_3;
    QLineEdit *centerLabel;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *exportToAsciiPushButton;
    QPushButton *exportToClipboardPushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MatrixDisplayDlg)
    {
        if (MatrixDisplayDlg->objectName().isEmpty())
            MatrixDisplayDlg->setObjectName(QStringLiteral("MatrixDisplayDlg"));
        MatrixDisplayDlg->resize(250, 140);
        MatrixDisplayDlg->setMinimumSize(QSize(0, 140));
        MatrixDisplayDlg->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_2 = new QVBoxLayout(MatrixDisplayDlg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Export = new QTabWidget(MatrixDisplayDlg);
        Export->setObjectName(QStringLiteral("Export"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, -1, 12, 12);
        maxTextEdit = new QTextEdit(tab);
        maxTextEdit->setObjectName(QStringLiteral("maxTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maxTextEdit->sizePolicy().hasHeightForWidth());
        maxTextEdit->setSizePolicy(sizePolicy);
        maxTextEdit->setReadOnly(true);

        verticalLayout->addWidget(maxTextEdit);

        Export->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(12, -1, 12, 12);
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        axisLabel = new QLineEdit(tab_2);
        axisLabel->setObjectName(QStringLiteral("axisLabel"));
        axisLabel->setReadOnly(true);

        gridLayout->addWidget(axisLabel, 0, 1, 1, 1);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        angleLabel = new QLineEdit(tab_2);
        angleLabel->setObjectName(QStringLiteral("angleLabel"));
        angleLabel->setReadOnly(true);

        gridLayout->addWidget(angleLabel, 1, 1, 1, 1);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        centerLabel = new QLineEdit(tab_2);
        centerLabel->setObjectName(QStringLiteral("centerLabel"));
        centerLabel->setReadOnly(true);

        gridLayout->addWidget(centerLabel, 2, 1, 1, 1);

        Export->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 12);
        exportToAsciiPushButton = new QPushButton(tab_3);
        exportToAsciiPushButton->setObjectName(QStringLiteral("exportToAsciiPushButton"));

        verticalLayout_3->addWidget(exportToAsciiPushButton);

        exportToClipboardPushButton = new QPushButton(tab_3);
        exportToClipboardPushButton->setObjectName(QStringLiteral("exportToClipboardPushButton"));

        verticalLayout_3->addWidget(exportToClipboardPushButton);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        Export->addTab(tab_3, QString());

        verticalLayout_2->addWidget(Export);


        retranslateUi(MatrixDisplayDlg);

        Export->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MatrixDisplayDlg);
    } // setupUi

    void retranslateUi(QWidget *MatrixDisplayDlg)
    {
        MatrixDisplayDlg->setWindowTitle(QApplication::translate("MatrixDisplayDlg", "Matrix", nullptr));
        maxTextEdit->setHtml(QApplication::translate("MatrixDisplayDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">1 0 0 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0 1 0 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0 0 1 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">"
                        "0 0 0 1</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", nullptr));
        Export->setTabText(Export->indexOf(tab), QApplication::translate("MatrixDisplayDlg", "Matrix", nullptr));
        label->setText(QApplication::translate("MatrixDisplayDlg", "Axis", nullptr));
        axisLabel->setText(QApplication::translate("MatrixDisplayDlg", "0 ; 0 ; 1", nullptr));
        label_2->setText(QApplication::translate("MatrixDisplayDlg", "Angle", nullptr));
        angleLabel->setText(QApplication::translate("MatrixDisplayDlg", "15.65 deg.", nullptr));
        label_3->setText(QApplication::translate("MatrixDisplayDlg", "Center", nullptr));
        centerLabel->setText(QApplication::translate("MatrixDisplayDlg", "0 ; 0;  0", nullptr));
        Export->setTabText(Export->indexOf(tab_2), QApplication::translate("MatrixDisplayDlg", "Axis/Angle", nullptr));
        exportToAsciiPushButton->setText(QApplication::translate("MatrixDisplayDlg", "ASCII", nullptr));
        exportToClipboardPushButton->setText(QApplication::translate("MatrixDisplayDlg", "Clipboard", nullptr));
        Export->setTabText(Export->indexOf(tab_3), QApplication::translate("MatrixDisplayDlg", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatrixDisplayDlg: public Ui_MatrixDisplayDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXDISPLAYDLG_H
