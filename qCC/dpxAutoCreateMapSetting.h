#ifndef _dpx_AutoCreateMap_SettingTool_h_
#define _dpx_AutoCreateMap_SettingTool_h_

//qCC_db
#include <ccHObject.h>

//Qt
#include <QSet>
#include "dpxVisibleSetting.h"

//! Graphical segmentation mechanism (with polyline)
class dpxAutoCreateMapSetting : public dpxVisibleSetting
{
public:
	explicit dpxAutoCreateMapSetting(ccGLWindow* associatedWin,QWidget* parent=0);
	virtual ~dpxAutoCreateMapSetting();

	virtual void accept();

public:
	void setMainWindow();
	void setActiveGLWindow(ccGLWindow* pGLWindow) { m_pGLWindow = pGLWindow;}
protected:
	bool AddPoleInfor(CCVector3 pt1,CCVector3 pt2,ccPointCloud* p3DVertices,ccPolyline* pBorderLine);
	void getRDisPt(CCVector3 ptFirst,CCVector3 ptSecond,double dDis,CCVector3& RDisPt);
protected:
	ccGLWindow* m_pGLWindow;
};

#endif //CC_GRAPHICAL_SEGMENTATION_TOOLS_HEADER
