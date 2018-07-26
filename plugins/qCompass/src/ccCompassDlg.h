//##########################################################################
//#                                                                        #
//#                    CLOUDCOMPARE PLUGIN: ccCompass                      #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                     COPYRIGHT: Sam Thiele  2017                        #
//#                                                                        #
//##########################################################################

#ifndef CC_COMPASS_DIALOG_HEADER
#define CC_COMPASS_DIALOG_HEADER

//Qt
#include <QDialog>
#include <QList>
#include <QAction>

//CC
#include <ccGLWindow.h>
#include <ccOverlayDialog.h>

//Local
#include <ui_compassDlg.h>
#include "ccTrace.h"

class ccCompassDlg : public ccOverlayDialog, public Ui::compassDlg
{
	Q_OBJECT

public:
	//! Default constructor
	explicit ccCompassDlg(QWidget* parent = 0);

	virtual bool eventFilter(QObject *obj, QEvent *e);


signals:
	void sigKeyPress(int nKey);
protected slots:
	//! To capture overridden shortcuts (pause button, etc.)
	void onShortcutTriggered(int);

private:
};

#endif
