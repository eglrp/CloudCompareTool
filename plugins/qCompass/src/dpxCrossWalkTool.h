
#ifndef _dpx_CrossWalkTool_TOOL_HEADER_
#define _dpx_CrossWalkTool_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccPolyline.h>
#include <ccFitPlane.h>
#include "dpxCrossWalkDlg.h"
#include "dpxPickAndEditTool.h"
#include "dpxPlaneAssistDlg.h"

/*
//斑马线工具
*/
class dpxCrossWalkTool : public dpxPickAndEditTool
{
	Q_OBJECT
public:
	dpxCrossWalkTool();
	virtual ~dpxCrossWalkTool();
public:
	virtual void toolActivated();
	virtual void toolDisactivated();
	virtual void onKeyPress(int sKey);
	//右键可取消两个点时的状态
	virtual void onMouseRightClick(int x,int y);
	virtual void onMouseReleaseEvent(int x,int y);
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);

public slots:
	virtual void slotDeleteObj();
	void slotChangeType(int nType);
protected:
	//采集多个点 最后拟合平面
	void PickMutilPts(const CCVector3& P ,int x,int y);
	void ThreePtPick(const CCVector3& P ,int x,int y);
	vector<ccPolyline*> CreatePlane(double& dWidth,int& nCount,std::vector<CCVector3>& BorderPts);

	double GetWidthFormBorderLine(ccPolyline* pInnerBorderLine);
	void setCrossWalkBorder(ccPolyline* pPoly3D,ccFitPlane* pPlane);

	ccPolyline* m_pBorderLine;
	ccFitPlane* m_pBorderPlane;
private:
	dpxPlaneAssistDlg* m_pAssistWin;
	int m_nCreateType; //是用采集还是用拟合到方式生成
};

#endif



