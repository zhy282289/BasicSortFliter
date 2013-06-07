#ifndef BASICSORTFLITER_H
#define BASICSORTFLITER_H

#include <QtGui/QMainWindow>
#include "ui_basicsortfliter.h"


class Widget;
class BasicSortFliter : public QMainWindow
{
	Q_OBJECT

public:
	BasicSortFliter(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BasicSortFliter();

private:
	Ui::BasicSortFliterClass ui;

	QWidget *m_widget;
};

#endif // BASICSORTFLITER_H
