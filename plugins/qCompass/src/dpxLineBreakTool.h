//class name:dpxCylinder
//brif:线打断工具
//

#ifndef _DPX_LINE_BREAK_Tool_
#define _DPX_LINE_BREAK_Tool_

#include "dpxNodeEditTool.h"

class dpxLineBreakTool : public dpxNodeEditTool
{
	Q_OBJECT
public:
	dpxLineBreakTool();
	virtual ~dpxLineBreakTool();

	//鼠标右键事件
	virtual void onMouseRightClick(int x,int y);
	//鼠标释放事件
	virtual void onMouseReleaseEvent(int x,int y);

public:
	//鼠标左键事件
	virtual void onMouseLeftClick(int x,int y);
};

#endif
