
#ifndef _dpx_Thread_Base_h__
#define _dpx_Thread_Base_h__

#pragma once
#include  <QThread>
//by duans
//////////////////////////////////////////////////////////////////////////
/** �߳����� */
class  dpxThreadBase : public QThread
{
	Q_OBJECT

public:
	explicit dpxThreadBase(void (*function)());
	virtual ~dpxThreadBase();

public slots:

protected:
	virtual void run();

protected:
	void  (*m_pFunc)();//����ָ��
};

//////////////////////////////////////////////////////////////////////////
#endif // gwBaseToolAssist_h__
