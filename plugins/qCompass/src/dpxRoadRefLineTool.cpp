
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxRoadRefLineTool.h"
#include "dpxGeoEngine.h"
#include "dpxMapDefine.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"
dpxRoadRefLineTool::dpxRoadRefLineTool()
{
}

dpxRoadRefLineTool::~dpxRoadRefLineTool()
{
}

void dpxRoadRefLineTool::onKeyPress(int sKey)
{
	//Q键清除选择集
	if(sKey == Qt::Key_Q)
	{
		dpxSelectionManager::Instance()->ClearSelection();
		dpxSelectionManager::Instance()->redrawSelectionSet();
	}
}


void dpxRoadRefLineTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState)//编辑状体
	{
        dpxNodeEditTool::onMouseRightClick(x,y);//添加节点功能
	}
	else//采集状态
	{
		if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
			return;

		unsigned vertCount = m_poly3D->size();
		if (vertCount < 2)
		{
			if (m_polyTip)
				m_polyTip->setEnabled(false);

			m_pPickRoot->removeChild(m_poly3D);
			m_poly3D = 0;
			m_poly3DVertices = 0;
		}
		else
		{
			ccColor::Rgb refLineColor REF_LINE_COLOR; //宏定义颜色
			m_poly3D->setTempColor(refLineColor);
			m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_RoadRefLine); //记录要素类型为refLine
			m_poly3D->setName("refLine");

			dpxSelectionManager::Instance()->AddObject2Selection(m_poly3D);
			dpxSelectionManager::Instance()->redrawSelectionSet();
			m_poly3D = 0;
			m_poly3DVertices = 0;
			m_nToolState = 1;//右键停止采集，转为编辑状态
		}
		m_polyTip->setEnabled(false);
		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
	}
}
