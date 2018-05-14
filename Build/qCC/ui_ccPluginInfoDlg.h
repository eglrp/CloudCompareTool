/********************************************************************************
** Form generated from reading UI file 'ccPluginInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPLUGININFODLG_H
#define UI_CCPLUGININFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ccPluginInfoDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListView *mPluginListView;
    QFrame *frame;
    QGridLayout *gridLayout;
    QTextEdit *mDescriptionTextEdit;
    QLabel *label_2;
    QTextBrowser *mAuthorsTextBrowser;
    QLabel *mNameLabel;
    QLabel *label_3;
    QFrame *line;
    QLabel *mPluginTypeLabel;
    QTextBrowser *mMaintainerTextBrowser;
    QLabel *mIcon;
    QLabel *label;
    QLabel *mReferencesLabel;
    QTextBrowser *mReferencesTextBrowser;
    QLabel *label_5;
    QTextEdit *mPluginPathTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ccPluginInfoDlg)
    {
        if (ccPluginInfoDlg->objectName().isEmpty())
            ccPluginInfoDlg->setObjectName(QStringLiteral("ccPluginInfoDlg"));
        ccPluginInfoDlg->resize(980, 750);
        verticalLayout = new QVBoxLayout(ccPluginInfoDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mPluginListView = new QListView(ccPluginInfoDlg);
        mPluginListView->setObjectName(QStringLiteral("mPluginListView"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mPluginListView->sizePolicy().hasHeightForWidth());
        mPluginListView->setSizePolicy(sizePolicy);
        mPluginListView->setMinimumSize(QSize(270, 0));
        mPluginListView->setMaximumSize(QSize(270, 16777215));
        mPluginListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mPluginListView->setIconSize(QSize(24, 24));
        mPluginListView->setUniformItemSizes(true);

        horizontalLayout->addWidget(mPluginListView);

        frame = new QFrame(ccPluginInfoDlg);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        mDescriptionTextEdit = new QTextEdit(frame);
        mDescriptionTextEdit->setObjectName(QStringLiteral("mDescriptionTextEdit"));
        mDescriptionTextEdit->setReadOnly(true);

        gridLayout->addWidget(mDescriptionTextEdit, 2, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        mAuthorsTextBrowser = new QTextBrowser(frame);
        mAuthorsTextBrowser->setObjectName(QStringLiteral("mAuthorsTextBrowser"));
        mAuthorsTextBrowser->setReadOnly(true);
        mAuthorsTextBrowser->setTextInteractionFlags(Qt::TextBrowserInteraction);
        mAuthorsTextBrowser->setOpenExternalLinks(true);

        gridLayout->addWidget(mAuthorsTextBrowser, 4, 1, 1, 1);

        mNameLabel = new QLabel(frame);
        mNameLabel->setObjectName(QStringLiteral("mNameLabel"));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        mNameLabel->setFont(font1);

        gridLayout->addWidget(mNameLabel, 0, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 1, 1, 1);

        mPluginTypeLabel = new QLabel(frame);
        mPluginTypeLabel->setObjectName(QStringLiteral("mPluginTypeLabel"));
        mPluginTypeLabel->setEnabled(false);
        mPluginTypeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(mPluginTypeLabel, 1, 0, 1, 1);

        mMaintainerTextBrowser = new QTextBrowser(frame);
        mMaintainerTextBrowser->setObjectName(QStringLiteral("mMaintainerTextBrowser"));
        mMaintainerTextBrowser->setReadOnly(true);
        mMaintainerTextBrowser->setOpenExternalLinks(true);

        gridLayout->addWidget(mMaintainerTextBrowser, 5, 1, 1, 1);

        mIcon = new QLabel(frame);
        mIcon->setObjectName(QStringLiteral("mIcon"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mIcon->sizePolicy().hasHeightForWidth());
        mIcon->setSizePolicy(sizePolicy2);
        mIcon->setMinimumSize(QSize(64, 64));
        mIcon->setPixmap(QPixmap(QString::fromUtf8(":/CC/Icons/images/icon/cc_icon_64.png")));
        mIcon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(mIcon, 0, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label, 4, 0, 1, 1);

        mReferencesLabel = new QLabel(frame);
        mReferencesLabel->setObjectName(QStringLiteral("mReferencesLabel"));
        mReferencesLabel->setFont(font);
        mReferencesLabel->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(mReferencesLabel, 6, 0, 1, 1);

        mReferencesTextBrowser = new QTextBrowser(frame);
        mReferencesTextBrowser->setObjectName(QStringLiteral("mReferencesTextBrowser"));
        mReferencesTextBrowser->setOpenExternalLinks(true);

        gridLayout->addWidget(mReferencesTextBrowser, 6, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);

        label_5 = new QLabel(ccPluginInfoDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        mPluginPathTextEdit = new QTextEdit(ccPluginInfoDlg);
        mPluginPathTextEdit->setObjectName(QStringLiteral("mPluginPathTextEdit"));
        mPluginPathTextEdit->setMinimumSize(QSize(0, 90));

        verticalLayout->addWidget(mPluginPathTextEdit);

        buttonBox = new QDialogButtonBox(ccPluginInfoDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ccPluginInfoDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ccPluginInfoDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ccPluginInfoDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ccPluginInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *ccPluginInfoDlg)
    {
        ccPluginInfoDlg->setWindowTitle(QApplication::translate("ccPluginInfoDlg", "Dialog", nullptr));
        label_2->setText(QApplication::translate("ccPluginInfoDlg", "Description", nullptr));
        mAuthorsTextBrowser->setHtml(QApplication::translate("ccPluginInfoDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        mAuthorsTextBrowser->setPlaceholderText(QApplication::translate("ccPluginInfoDlg", "(none listed)", nullptr));
        mNameLabel->setText(QApplication::translate("ccPluginInfoDlg", "Plugins", nullptr));
        label_3->setText(QApplication::translate("ccPluginInfoDlg", "Maintainers", nullptr));
        mPluginTypeLabel->setText(QString());
        mMaintainerTextBrowser->setHtml(QApplication::translate("ccPluginInfoDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        mMaintainerTextBrowser->setPlaceholderText(QApplication::translate("ccPluginInfoDlg", "(CloudCompare Team)", nullptr));
        mIcon->setText(QString());
        label->setText(QApplication::translate("ccPluginInfoDlg", "Authors", nullptr));
        mReferencesLabel->setText(QApplication::translate("ccPluginInfoDlg", "References", nullptr));
        mReferencesTextBrowser->setHtml(QApplication::translate("ccPluginInfoDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        mReferencesTextBrowser->setPlaceholderText(QApplication::translate("ccPluginInfoDlg", "(none listed)", nullptr));
        label_5->setText(QApplication::translate("ccPluginInfoDlg", "CloudCompare looks for plugins in the following directories:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ccPluginInfoDlg: public Ui_ccPluginInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPLUGININFODLG_H
