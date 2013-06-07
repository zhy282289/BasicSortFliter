#include "stdafx.h"
#include "basicsortfliter.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BasicSortFliter w;
	w.showMaximized();
	return a.exec();
}
