#include "stdafx.h"
#include "basicsortfliter.h"

#include "widget.h"
BasicSortFliter::BasicSortFliter(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	m_widget = new Widget;
	setCentralWidget(m_widget);
}

BasicSortFliter::~BasicSortFliter()
{

}
