
#ifndef dpxToolAssist_Dlg_h__
#define dpxToolAssist_Dlg_h__

#pragma once
#include  <QDialog>
#include "ccTool.h"

//////////////////////////////////////////////////////////////////////////
/** 工具助手 */
class  dpxToolAssistDlg : public QDialog
{
	Q_OBJECT

public:
	explicit dpxToolAssistDlg(ccTool* pTool);
	virtual ~dpxToolAssistDlg();

public slots:
	/** 重载基类函数 */
	virtual void setVisible(bool visible);

	virtual void reject() ;

	/** 同步参数信息 */
	virtual void slotSyncParam();

protected:
	/** 读取配置信息 */
	void readSettings();
	/** 保存配置信息 */
	void writeSettings();

	/** 初始化助手-在show的时候会调用 */
	virtual bool InitToolAssit();

protected:
	ccTool* m_pTool;
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
