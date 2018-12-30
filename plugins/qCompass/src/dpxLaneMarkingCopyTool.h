
#ifndef _DPX_dpxLaneMarkingCopyTool_h_
#define _DPX_dpxLaneMarkingCopyTool_h_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>

#include "dpxTraceLineTool.h"


/*
Tool used to digitise traces
*/
class dpxLaneMarkingCopyTool : public dpxTraceLineTool
{
public:
	dpxLaneMarkingCopyTool();
	virtual ~dpxLaneMarkingCopyTool();
public:
	virtual void toolActivated();

	//重写基类原因：摁快捷键盘时，需要切换线拷贝的功能，
	//点击refLine 拷贝形成车道线
	virtual void onMouseLeftClick(int x,int y);

	//补充了拷贝模式下点击右键，恢复至编辑模式
	virtual void onMouseRightClick(int x,int y);

	//补充拷贝模式下，虚线不显示
	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);

	//在dpxNodeEditTool基类下,控制不能修改refLine
	virtual void onMouseReleaseEvent(int x,int y);
	//补充拷贝状态，点一个点就拷贝线
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);
	//键盘事件
	virtual void onKeyPress(int key);

protected:
	void CheckSelectRefLine();

public slots:
	virtual void slotDeleteObj();

private:
	bool m_bSetTargetLine;
};

#endif
