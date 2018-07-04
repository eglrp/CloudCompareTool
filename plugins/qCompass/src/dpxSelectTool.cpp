//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include "dpxSelectTool.h"
#include "ccCylinder.h"
#include "dpxAlgorithmFun.h"

dpxSelectTool::dpxSelectTool()
	: dpxNodeEditTool()
{
}

dpxSelectTool::~dpxSelectTool()
{
}

void dpxSelectTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
}
