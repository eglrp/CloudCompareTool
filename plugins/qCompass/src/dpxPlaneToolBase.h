//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_PLANE_TOOL_BASE_HEADER_
#define _DPX_PLANE_TOOL_BASE_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>
#include <QImage>
#include <QObject>
#include <ccFitPlane.h>

#include "dpxPickAndEditTool.h"
#include "dpxPlaneAssistDlg.h"

#include "dpxMapDefine.h"

/*
Tool used to digitise traces
*/

class dpxPlaneToolBase : public dpxPickAndEditTool
{
	Q_OBJECT
public:
	dpxPlaneToolBase();
	virtual ~dpxPlaneToolBase();

public:
	virtual void toolActivated();
	virtual void toolDisactivated();
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	virtual void onMouseReleaseEvent(int x,int y);
	virtual void onMouseRightClick(int x,int y);

protected:
	void AddPlaneToData(ccFitPlane* pPlane);
	//void  PtFitPlane();
	void  PickMutilPts(const CCVector3& P ,int x,int y);
	void  ThreePtPick(const CCVector3& P ,int x,int y);

//	QString getImageName();//每种类型的纹理图片
//	QString getObjectName();

protected slots:
	void slotChangeType(int nType);
	void slotObjTypeChangeType(int nObjType);


protected:
	dpxPlaneAssistDlg* m_pAssistWin;
	int m_nCreateType; //是用采集还是用拟合到方式生成

	//派生工具需要设定
	dpxObjectType m_eCurObjType; //当前采集的要素是什么类型
	QString m_strImageName;//ImageName 背景颜色图片
	QString m_strccHobjectName;//目录树的显示名称
	dpxLayerType m_eTargetLayerType;
};

#endif
