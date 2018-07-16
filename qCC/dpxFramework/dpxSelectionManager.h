
#ifndef _dpx_SELECTION_MANAGER_HEADER_
#define _dpx_SELECTION_MANAGER_HEADER_

//by duans  全局的单例
#include <QString>
#include <QObject>

# include "CCTypes.h"
#include "ccHObject.h"
#include "ccPolyline.h"
#include "ccSphere.h"
#include "dpxSnapHelper.h"

//选择集
class dpxSelectionManager : public QObject
{
public:
	static dpxSelectionManager* Instance();
public:

	vector<ccHObject*> getSelections() { return m_vecSeltHObjs; }
	//获取选择集大小
	int  getSelectionSize();
	//几何是否被选择
	bool isInSelectSet(ccHObject* pHObject);
	//清空所有选择的对象
	void ClearSelection();
	//bOnlyOne代表是否清除其它临时显示项
	void AddObject2Selection(ccHObject* pHObject,bool bOnlyOne = true);
	void RemoveSelection(ccHObject* pHObject);

	void redrawSelectionSet();
protected:
	void rebackColor();
private:
	vector<ccHObject*> m_vecSeltHObjs;

	//显示的节点
	ccHObject* m_pShowSelectObject;
	//当前激活的ccGLWindow
	ccGLWindow* m_pCurActiveWindow;
private:
	dpxSelectionManager();
	dpxSelectionManager(const dpxSelectionManager&){}
	dpxSelectionManager& operator=(const dpxSelectionManager&){}
};


#endif //dpxSelectionManager
