#ifdef CC_LAS_SUPPORT
#include "dpxDataPretreat.h"
dpxDataPretreat::dpxDataPretreat()
{
}

dpxDataPretreat::~dpxDataPretreat()
{
}

bool dpxDataPretreat::PretreatFiles()
{
	QString strInputPath = m_param.strInputPath;
	QString strOutputPath = m_param.strOutputPath;

	QFileInfoList InfoList = QDir(strInputPath).entryInfoList();//获取当前目录所有文件
	QFileInfoList targetInfoList;//定义放提取文件的List
	//遍历
	foreach(QFileInfo fileInfo,InfoList)
	{
		if(!fileInfo.isFile())
			continue;
		ccLog::Warning(fileInfo.suffix());
		if(0==fileInfo.suffix().compare("las",Qt::CaseInsensitive))
			targetInfoList << fileInfo;//指定后缀，加入列表
	}

	if(targetInfoList.size()==0)
		return false;

	if(0)
	{
		//单个文件降采样模式
		for(int i = 0;i<targetInfoList.size();i++)
		{
			QFileInfo fileInfo = targetInfoList.at(i);
			QString strFile = fileInfo.filePath();
			loadFileV2(strFile);
			ccLog::Warning("process Num" + QString::number(i+1)+ ",Total Num" + QString::number(targetInfoList.size()));
		}
		return true;
	}
	else
	{
		//多个文件合并重新切割模式
		return MergeAndReTile(targetInfoList);
	}


}

bool dpxDataPretreat::MergeAndReTile(QFileInfoList TargetInfoList)
{
	vector<PointViewPtr> pointViews;
	unsigned int nbOfPoints = 0;
	double dMinX = DBL_MAX,dMinY= DBL_MAX,dMinZ= DBL_MAX;
	double dMaxX=DBL_MIN,dMaxY=DBL_MIN,dMaxZ=DBL_MIN;
	QString strExt = "";
	QScopedPointer<ccProgressDialog> pDlg(0);

	//单个文件降采样模式
	for(int i = 0;i<TargetInfoList.size();i++)
	{
		QFileInfo fileInfo = TargetInfoList.at(i);
		QString filename = fileInfo.filePath();
		Options las_opts;
		las_opts.add("filename", filename.toLocal8Bit().toStdString());

		FixedPointTable t(100);
		LasReader lasReader;
		LasHeader lasHeader;

		PointTable table;
		PointViewSet pointViewSet;


		try
		{
			lasReader.setOptions(las_opts);
			lasReader.prepare(t);
			lasHeader = lasReader.header();
		}
		catch (const std::exception& e)
		{
			continue;
		}

		dMinX = dMinX<lasHeader.minX() ? dMinX : lasHeader.minX();
		dMinY = dMinY<lasHeader.minY() ? dMinY : lasHeader.minY();
		dMinZ = dMinZ<lasHeader.minZ() ? dMinZ : lasHeader.minZ();

		dMaxX = dMaxX>lasHeader.maxX() ? dMaxX : lasHeader.maxX();
		dMaxY = dMaxY>lasHeader.maxY() ? dMaxY : lasHeader.maxY();
		dMaxZ = dMaxZ>lasHeader.maxZ() ? dMaxZ : lasHeader.maxZ();

		//File extension
		strExt = (lasHeader.compressed() ? "laz" : "las");
		unsigned int nCount = lasHeader.pointCount();
		nbOfPoints += nCount;


		pDlg.reset(new ccProgressDialog(true, 0)); //cancel available
		pDlg->setMethodTitle(QObject::tr("Open LAS file"));
		pDlg->setInfo(QObject::tr("Points: %L1").arg(nCount));
		pDlg->start();



		auto prepareAndExecture = [&lasReader, &table]() -> PointViewSet {
			lasReader.prepare(table);
			lasReader.prepare(table);
			return lasReader.execute(table);
		};

		//进程窗体
		{
			pDlg.reset(new ccProgressDialog(false, 0));
			pDlg->setMethodTitle(QObject::tr("LAS file"));
			pDlg->setInfo(QObject::tr("Please wait... reading in progress"));
			pDlg->setRange(0, 0);
			pDlg->setModal(true);
			pDlg->start();
		}

		QFutureWatcher<PointViewSet> reader;
		QObject::connect(&reader, SIGNAL(finished()), pDlg.data(), SLOT(reset()));
		reader.setFuture(QtConcurrent::run(prepareAndExecture));

		if (pDlg)
		{
			pDlg->exec();
		}
		reader.waitForFinished();
		PointViewSet viewSet = reader.result();
		int nSize =  viewSet.size();
		PointViewPtr pointView = *viewSet.begin();
		pointViews.push_back(pointView);
	}
	//------------------------------------
	//test Merge not tile
	{
			LasWriter writer;
			Options writerOptions;
			PointTable table;
			BufferReader bufferReader;

			writerOptions.add("filename", "Merge");
			for(int i =0;i<pointViews.size();i++)
				bufferReader.addView(pointViews[0]);

			try
			{
				writer.setInput(bufferReader);
				writer.setOptions(writerOptions);
				writer.prepare(table);
				writer.execute(table);
				ccLog::Warning("write finished");
			}
			catch (const pdal_error& e)
			{
				ccLog::Error(QString("PDAL exception '%1'").arg(e.what()));
			}
			return true ;
	}


	return true;
	//------------------------------------------------------------------//
	Tiler tiler;
	PointTable table;
	// tiling (vertical) dimension
	unsigned int vertDim = m_param.vertDim;
	unsigned int w = m_param.w;
	unsigned int h = m_param.h;
	QString outputBaseName = m_param.strOutputPath + "/Merge";
	CCVector3d bbMin(dMinX,dMinY,dMinZ);
	CCVector3d bbMax(dMaxX,dMaxY,dMaxZ);
	if (!tiler.init(w, h, vertDim, outputBaseName, bbMin, bbMax, table, strExt))
		return false;

//	if (pDlg)
//	{
//		pDlg.reset(new ccProgressDialog(true, 0)); //cancel available
//		pDlg->setMethodTitle(QObject::tr("Tiling points"));
//		pDlg->setInfo(QObject::tr("Points: %L1").arg(nbOfPoints));
//		pDlg->start();
//	}
	//CCLib::NormalizedProgress nProgress(pDlg.data(), nbOfPoints);

	for(int i = 0;i<pointViews.size();i++)
	{
		//读取到的点云添加到切片里
		for (PointId idx = 0; idx < pointViews[i]->size(); ++idx)
		{
			//if (pDlg->isCancelRequested())
				//return false;
			//if( idx%3 != 0) //降采样  只能保留1/3
				//continue;
			tiler.addPoint(pointViews[i], idx);
			//nProgress.oneStep();
		}

		//Write写操作
//		{
//			pDlg.reset(new ccProgressDialog(false, 0));
//			pDlg->setMethodTitle(QObject::tr("LAS file"));
//			pDlg->setInfo(QObject::tr("Please wait... writing in progress"));
//			pDlg->setRange(0, 0);
//			pDlg->setModal(true);
//			pDlg->start();
//		}
	}

	//QFutureWatcher<void> writer;
	//QObject::connect(&writer, SIGNAL(finished()), pDlg.data(), SLOT(reset()));
	//writer.setFuture(QtConcurrent::run([&tiler]() {tiler.writeAll(); }));

	//pDlg->exec();
	//writer.waitForFinished();

	tiler.writeAll();
	ccLog::Warning("write all finished");
	return false;
}



bool dpxDataPretreat::loadFileV2(const QString& filename)
{
	Options las_opts;
	las_opts.add("filename", filename.toLocal8Bit().toStdString());

	FixedPointTable t(100);
	LasReader lasReader;
	LasHeader lasHeader;
	try
	{
		lasReader.setOptions(las_opts);
		lasReader.prepare(t);
		lasHeader = lasReader.header();
	}
	catch (const std::exception& e)
	{
		return false;
	}
	catch (...)
	{
		return false;
	}


	CCVector3d bbMin(lasHeader.minX(), lasHeader.minY(), lasHeader.minZ());
	CCVector3d bbMax(lasHeader.maxX(), lasHeader.maxY(), lasHeader.maxZ());

	CCVector3d lasScale = CCVector3d(lasHeader.scaleX(), lasHeader.scaleY(), lasHeader.scaleZ());
	CCVector3d lasShift = -CCVector3d(lasHeader.offsetX(), lasHeader.offsetY(), lasHeader.offsetZ());

			//File extension
	QString ext = (lasHeader.compressed() ? "laz" : "las");

	unsigned int nbOfPoints = lasHeader.pointCount();
	if (nbOfPoints == 0)
		return true;

	QScopedPointer<ccProgressDialog> pDlg(0);
	pDlg.reset(new ccProgressDialog(true, 0)); //cancel available
	pDlg->setMethodTitle(QObject::tr("Open LAS file"));
	pDlg->setInfo(QObject::tr("Points: %L1").arg(nbOfPoints));
	pDlg->start();

	Tiler tiler;
	PointTable table;
	PointViewSet pointViewSet;

	// tiling (vertical) dimension
	unsigned int vertDim = m_param.vertDim;
	unsigned int w = m_param.w;
	unsigned int h = m_param.h;

	QString outputBaseName = m_param.strOutputPath + "/" + QFileInfo(filename).baseName();
	if (!tiler.init(w, h, vertDim, outputBaseName, bbMin, bbMax, table, ext))
		return false;

	auto prepareAndExecture = [&lasReader, &table]() -> PointViewSet {
		lasReader.prepare(table);
		lasReader.prepare(table);
		return lasReader.execute(table);
	};

	//进程窗体
	{
		pDlg.reset(new ccProgressDialog(false, 0));
		pDlg->setMethodTitle(QObject::tr("LAS file"));
		pDlg->setInfo(QObject::tr("Please wait... reading in progress"));
		pDlg->setRange(0, 0);
		pDlg->setModal(true);
		pDlg->start();
	}

	QFutureWatcher<PointViewSet> reader;
	QObject::connect(&reader, SIGNAL(finished()), pDlg.data(), SLOT(reset()));
	reader.setFuture(QtConcurrent::run(prepareAndExecture));

	if (pDlg)
	{
		pDlg->exec();
	}
	reader.waitForFinished();

	PointViewSet viewSet = reader.result();
	int nSize =  viewSet.size();
	ccLog::Warning( "viewSet Size" + QString::number(nSize));
	PointViewPtr pointView = *viewSet.begin();

	if (pDlg)
	{
		pDlg.reset(new ccProgressDialog(true, 0)); //cancel available
		pDlg->setMethodTitle(QObject::tr("Tiling points"));
		pDlg->setInfo(QObject::tr("Points: %L1").arg(nbOfPoints));
		pDlg->start();
	}
	CCLib::NormalizedProgress nProgress(pDlg.data(), nbOfPoints);
	ccLog::Warning("pointView Size=" + QString::number(pointView->size()));

	//读取到的点云添加到切片里
	for (PointId idx = 0; idx < pointView->size(); ++idx)
	{
		if (pDlg->isCancelRequested())
			return false;
		if( idx%3 != 0) //降采样  只能保留1/3
			continue;
		tiler.addPoint(pointView, idx);
		nProgress.oneStep();
	}

	//Write写操作
	{
		pDlg.reset(new ccProgressDialog(false, 0));
		pDlg->setMethodTitle(QObject::tr("LAS file"));
		pDlg->setInfo(QObject::tr("Please wait... writing in progress"));
		pDlg->setRange(0, 0);
		pDlg->setModal(true);
		pDlg->start();
	}

	QFutureWatcher<void> writer;
	QObject::connect(&writer, SIGNAL(finished()), pDlg.data(), SLOT(reset()));
	writer.setFuture(QtConcurrent::run([&tiler]() {tiler.writeAll(); }));

	pDlg->exec();
	writer.waitForFinished();
	return false;
}
#endif
