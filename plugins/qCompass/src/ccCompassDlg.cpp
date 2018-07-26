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

#include "ccCompassDlg.h"

//Local
#include "ccGLWindow.h"

//qCC_db
#include <ccLog.h>

//Qt
#include <QEvent>
#include <QKeyEvent>
#include <QApplication>
#include <qmenu.h>
#include <qaction.h>

//system
#include <assert.h>

ccCompassDlg::ccCompassDlg(QWidget* parent/*=0*/)
	: ccOverlayDialog(parent)
	, Ui::compassDlg()
{
	setupUi(this);

	//set background color
	QPalette p;
	p.setColor(backgroundRole(), QColor(240, 240, 240, 200));
	setPalette(p);
	setAutoFillBackground(true);

	//add shortcuts
	addOverridenShortcut(Qt::Key_Escape); //escape key for the "cancel" button
	addOverridenShortcut(Qt::Key_Return); //return key for the "apply" button
	addOverridenShortcut(Qt::Key_Space); //space key also hits the "apply" button (easier for some)
	connect(this, SIGNAL(shortcutTriggered(int)), this, SLOT(onShortcutTriggered(int)));
}

bool ccCompassDlg::eventFilter(QObject *obj, QEvent *e)
{
	if (e->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e);
		emit sigKeyPress(keyEvent->key());
	}
	//emit();
	return ccOverlayDialog::eventFilter(obj,e);
}


void ccCompassDlg::onShortcutTriggered(int key)
{
	switch (key)
	{
	case Qt::Key_Return:
		//acceptButton->click();
		return;
	case Qt::Key_Space:
		//acceptButton->click();
		return;
	case Qt::Key_Escape:
		closeButton->click();
		return;
	default:
		//nothing to do
		break;
	}
}
