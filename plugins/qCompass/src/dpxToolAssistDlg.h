
#ifndef dpxToolAssist_Dlg_h__
#define dpxToolAssist_Dlg_h__

#pragma once
#include  <QDialog>
#include "ccTool.h"

//////////////////////////////////////////////////////////////////////////
/** �������� */
class  dpxToolAssistDlg : public QDialog
{
	Q_OBJECT

public:
	explicit dpxToolAssistDlg(ccTool* pTool);
	virtual ~dpxToolAssistDlg();

public slots:
	/** ���ػ��ຯ�� */
	virtual void setVisible(bool visible);

	virtual void reject() ;

	/** ͬ��������Ϣ */
	virtual void slotSyncParam();

protected:
	/** ��ȡ������Ϣ */
	void readSettings();
	/** ����������Ϣ */
	void writeSettings();

	/** ��ʼ������-��show��ʱ������ */
	virtual bool InitToolAssit();

protected:
	ccTool* m_pTool;
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
