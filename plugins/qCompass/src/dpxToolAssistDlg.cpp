
#include "dpxToolAssistDlg.h"
#include  <QSettings>
#include  <QApplication>
#include  <QMainWindow>
#include  <QWidget>
//////////////////////////////////////////////////////////////////////////

dpxToolAssistDlg::dpxToolAssistDlg(ccTool* pTool)
{
	m_pTool = pTool;
	QMainWindow* pMainWindow = pTool->getMainWindow();
	setParent(pMainWindow);
	setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint);
}

dpxToolAssistDlg::~dpxToolAssistDlg()
{
	writeSettings();
}

void dpxToolAssistDlg::setVisible(bool visible)
{
	if (visible == isVisible()) {
		return;
	}

	QDialog::setVisible(visible);
	if (visible)
	{
		if (!InitToolAssit()) {
			return;
		}

		readSettings();
	}
	else
	{
		writeSettings();
	}
}

void dpxToolAssistDlg::reject()
{
	if (m_pTool != NULL)
	{
		m_pTool->toolDisactivated();
	}

	QDialog::reject() ;
}

void dpxToolAssistDlg::readSettings()
{
	if (NULL == m_pTool) {
		return;
	}

	QSettings settings(QSettings::SystemScope,QApplication::organizationName(), QApplication::applicationName());
	settings.beginGroup("dpxToolAssist");
	QString toolName = m_pTool->GetToolName();
	QPoint pos = settings.value(toolName + "/pos", QPoint(200, 200)).toPoint();
	QSize size = settings.value(toolName + "/size", QSize(100, 100)).toSize();
	resize(size);
	move(pos);
}

void dpxToolAssistDlg::writeSettings()
{
	if (NULL == m_pTool) {
		return;
	}
	//记录助手的位置和大小
	QSettings settings(QSettings::SystemScope,QApplication::organizationName(), QApplication::applicationName());
	settings.beginGroup("dpxToolAssist");
	QString toolName = m_pTool->GetToolName();
	settings.setValue(toolName + "/pos", pos());
	settings.setValue(toolName + "/size", size());

	settings.endGroup();
}

void dpxToolAssistDlg::slotSyncParam()
{
	if (NULL == m_pTool) {
		return;
	}
}

bool dpxToolAssistDlg::InitToolAssit()
{
	return true;
}
