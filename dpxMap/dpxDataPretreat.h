
//by duans 2018.9.20
#ifndef _DPX_DataPretreat_H_
#define _DPX_DataPretreat_H_
#pragma once

#include "dpxMap_IO.h"
#include <ccHObject.h>

//qCC_db
#include <ccLog.h>
#include <ccPointCloud.h>
#include <ccProgressDialog.h>
#include <ccScalarField.h>
#include "ccColorScalesManager.h"

//CCLib
#include <CCPlatform.h>

//Qt
#include <QFileInfo>
#include <QSharedPointer>
#include <QInputDialog>
#include <QFuture>
#include <QtConcurrent>
#include <QString>

//pdal
#include <memory>
#include <pdal/PointTable.hpp>
#include <pdal/PointView.hpp>
#include <pdal/Options.hpp>
#include <pdal/Dimension.hpp>
#include <pdal/io/LasReader.hpp>
#include <pdal/io/LasHeader.hpp>
#include <pdal/io/LasWriter.hpp>
#include <pdal/io/LasVLR.hpp>
#include <pdal/io/BufferReader.hpp>
#include <pdal/Filter.hpp>
#include <pdal/filters/StreamCallbackFilter.hpp>

Q_DECLARE_METATYPE(pdal::SpatialReference)


using namespace pdal::Dimension;
using namespace pdal;

struct DPX_MAP_API pdxPretreatParams
{
	unsigned int vertDim ;
	unsigned int w;
	unsigned int h;
    QString strInputPath;
    QString strOutputPath;
    int nDownSamplingRatio; //降采样比率  降低为整数倍
	pdxPretreatParams()
	{
		vertDim = 2;
		w = 2;
		h = 2;
		strInputPath = "";
		strOutputPath = "";
		nDownSamplingRatio = 1;
	}
};


//! Class describing the current tiling process
class Tiler
{
public:
	Tiler()
		: w(1)
		, h(1)
		, X(0)
		, Y(1)
		, Z(2)
	{}

	~Tiler() = default;

	inline size_t tileCount() const { return tilePointViews.size(); }

	bool init(unsigned int width,
		unsigned int height,
		unsigned int Zdim,
		QString absoluteBaseFilename,
		const CCVector3d& bbMin,
		const CCVector3d& bbMax,
		const PointTableRef table,
		const QString& ext)
	{
		//init tiling dimensions
		assert(Zdim < 3);
		Z = Zdim;
		X = (Z == 2 ? 0 : Z + 1);
		Y = (X == 2 ? 0 : X + 1);

		bbMinCorner = bbMin;
		tileDiag = bbMax - bbMin;
		tileDiag.u[X] /= width;
		tileDiag.u[Y] /= height;
		unsigned int count = width * height;

		try
		{
			tilePointViews.resize(count);
			fileNames.resize(count);
		}
		catch (const std::bad_alloc&)
		{
			//not enough memory
			return false;
		}

		w = width;
		h = height;

		for (unsigned int i = 0; i < width; ++i)
		{
			for (unsigned int j = 0; j < height; ++j)
			{
				unsigned int ii = index(i, j);
				QString filename = absoluteBaseFilename + QString("_%1_%2.%3").arg(QString::number(i), QString::number(j), ext);

				fileNames[ii] = filename;
				tilePointViews[ii] = PointViewPtr(new PointView(table));
				ccLog::Warning("tilePointViews Size =====" + QString::number(tilePointViews[ii]->size()));
			}
		}

		return true;
	}

	void addPoint(const PointViewPtr buffer, unsigned int pointIndex)
	{
		//determine the right tile
		CCVector3d Prel = CCVector3d( buffer->getFieldAs<double>(Id::X, pointIndex),
									  buffer->getFieldAs<double>(Id::Y, pointIndex),
									  buffer->getFieldAs<double>(Id::Z, pointIndex) );
		Prel -= bbMinCorner;
		int ii = static_cast<int>(floor(Prel.u[X] / tileDiag.u[X]));
		int ji = static_cast<int>(floor(Prel.u[Y] / tileDiag.u[Y]));
		unsigned int i = std::min(static_cast<unsigned int>(std::max(ii, 0)), w - 1);
		unsigned int j = std::min(static_cast<unsigned int>(std::max(ji, 0)), h - 1);
		PointViewPtr outputView = tilePointViews[index(i, j)];
		outputView->appendPoint(*buffer, pointIndex);
	}

	void writeAll()
	{
		for (unsigned int i = 0; i < tilePointViews.size(); ++i)
		{
			LasWriter writer;
			Options writerOptions;
			PointTable table;
			BufferReader bufferReader;

			writerOptions.add("filename", fileNames[i].toLocal8Bit().toStdString());
			ccLog::Warning("tilePointViews Size =" + QString::number(tilePointViews[i]->size()));
			if (tilePointViews[i]->empty())
				continue;
			try
			{
				bufferReader.addView(tilePointViews[i]);
				writer.setInput(bufferReader);
				writer.setOptions(writerOptions);
				writer.prepare(table);
				writer.execute(table);
			}
			catch (const pdal_error& e)
			{
				ccLog::Error(QString("PDAL exception '%1'").arg(e.what()));
			}
		}
	}

protected:

	inline unsigned int index(unsigned int i, unsigned int j) const { return i + j * w; }

	unsigned int w, h;
	unsigned int X, Y, Z;
	CCVector3d bbMinCorner, tileDiag;
	std::vector<PointViewPtr> tilePointViews;
	std::vector<QString> fileNames;
};


class  DPX_MAP_API dpxDataPretreat
{
public:
	dpxDataPretreat();
	virtual ~dpxDataPretreat();

public:
	bool PretreatFiles();
	void setPretreatParam(pdxPretreatParams param) {m_param = param;}
	//static accessorsm_param
	static inline QString GetFileFilter() { return "LAS cloud (*.las *.laz)"; }
	static inline QString GetDefaultExtension() { return "las"; }

	bool MergeAndReTile(QFileInfoList TargetInfoList);  //合并文件并重新切割
	bool loadFileV2(const QString& filename);

protected:
	pdxPretreatParams m_param;
};

#endif
