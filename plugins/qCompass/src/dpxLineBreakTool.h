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

public:
	//鼠标左键事件
	virtual void onMouseLeftClick(int x,int y);
};

#endif
