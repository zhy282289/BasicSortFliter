#include "StdAfx.h"
#include "widget.h"

#include "mymodel.h"
Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	CreateUi();
}

Widget::~Widget()
{

}

void Widget::CreateUi()
{
	//m_sourceModel = new QStandardItemModel(0, 3, this);
	//CreateSourceModel(m_sourceModel);

	m_myModel = new MyModel(this);
	m_sourceView = new QTableView;
	m_sourceView->horizontalHeader()->setStretchLastSection(true);
	m_sourceView->verticalHeader()->hide();
	m_sourceView->setAlternatingRowColors(true);
	m_sourceView->setSelectionMode(QAbstractItemView::SingleSelection);
	m_sourceView->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_sourceView->setModel(m_myModel);
	//m_sourceView->hide();

	m_proxyModel = new QSortFilterProxyModel(this);
	m_proxyModel->setSourceModel(m_myModel);
	m_proxyModel->setDynamicSortFilter(true);
	m_proxyModel->setFilterRole(Qt::UserRole + 1);
	m_proxyView = new QTableView;
	m_proxyView->horizontalHeader()->setStretchLastSection(true);
	m_proxyView->verticalHeader()->hide();
	m_proxyView->setAlternatingRowColors(true);
	m_proxyView->setSelectionMode(QAbstractItemView::SingleSelection);
	m_proxyView->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_proxyView->setModel(m_proxyModel);



	m_sourceGroupBox = new QGroupBox("Source Model");
	QVBoxLayout *sourceLayout = new QVBoxLayout;
	sourceLayout->addWidget(m_sourceView);
	m_sourceGroupBox->setLayout(sourceLayout);

	QLabel *filterPattemLabel = new QLabel("&Filter pattem:");
	m_pattemLineEdit = new QLineEdit;

	m_syntaxCombo = new QComboBox;
	m_syntaxCombo->addItem("Regular expression", QRegExp::RegExp);
	m_syntaxCombo->addItem("Wildcard", QRegExp::Wildcard);
	m_syntaxCombo->addItem("Fixed string", QRegExp::FixedString);
	QLabel *syntaxLabel = new QLabel("&Filter syntax:");
	syntaxLabel->setBuddy(m_syntaxCombo);

	m_columnCombo = new QComboBox;
	m_columnCombo->addItem("column 1");
	m_columnCombo->addItem("column 2");
	m_columnCombo->addItem("column 3");
	QLabel *columnLabel = new QLabel("&Filter column:");
	columnLabel->setBuddy(m_columnCombo);

	m_sensitiveFilter = new QCheckBox("Case Sensitive Filter");
	m_sensitiveSort = new QCheckBox("Case Sensitive Sortting");

	QGridLayout *proxyLayout = new QGridLayout;
	proxyLayout->addWidget(m_proxyView, 0, 0, 1, 2);
	proxyLayout->addWidget(filterPattemLabel, 1, 0, 1, 1);
	proxyLayout->addWidget(m_pattemLineEdit, 1, 1, 1, 1);

	proxyLayout->addWidget(syntaxLabel, 2, 0, 1, 1);
	proxyLayout->addWidget(m_syntaxCombo, 2, 1, 1, 1);
	proxyLayout->addWidget(columnLabel, 3, 0, 1, 1);
	proxyLayout->addWidget(m_columnCombo, 3, 1, 1, 1);
	proxyLayout->addWidget(m_sensitiveFilter, 4, 0, 1, 1);
	proxyLayout->addWidget(m_sensitiveSort, 4, 1, 1, 1);
	proxyLayout->setColumnStretch(0, 30);
	proxyLayout->setColumnStretch(1, 70);


	m_proxyGroupBox = new QGroupBox("Sort Filter/Model");
	m_proxyGroupBox->setLayout(proxyLayout);

	QVBoxLayout *vlayout = new QVBoxLayout;
	vlayout->addWidget(m_sourceGroupBox);
	vlayout->addWidget(m_proxyGroupBox);

	setLayout(vlayout);

	connect(m_pattemLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(FilterChanged()));
	connect(m_syntaxCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(FilterChanged()));
	connect(m_columnCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(FilterColumnChanged()));
	connect(m_sensitiveFilter, SIGNAL(stateChanged(int)), this, SLOT(FilterChanged()));
	connect(m_sensitiveSort, SIGNAL(stateChanged(int)), this, SLOT(SortSensitiveChanged()));


}

void Widget::CreateSourceModel( QStandardItemModel *model )
{
	model->setHeaderData(0, Qt::Horizontal, "no1");
	model->setHeaderData(1, Qt::Horizontal, "no2");
	model->setHeaderData(2, Qt::Horizontal, "no3");


	for (int i = 0; i < 8; ++i)
	{
		AddModelItem(model, QString("Boy%1").arg(QSTR(i)),QString("Fuck%1").arg(QSTR(i)),QString("Girl%1").arg(QSTR(i)));
	}


	


}

void Widget::AddModelItem( QStandardItemModel *model, const QString &s1,const QString &s2,const QString &s3 )
{
	QList<QStandardItem*> itemList;
	itemList << new QStandardItem(s1) << new QStandardItem(s2) << new QStandardItem(s3);
	model->appendRow(itemList);
}

void Widget::FilterChanged()
{
	QRegExp::PatternSyntax syntax =
		QRegExp::PatternSyntax(m_syntaxCombo->itemData(
		m_syntaxCombo->currentIndex()).toInt());
	Qt::CaseSensitivity caseSensitivity =
		m_sensitiveFilter->isChecked() ? Qt::CaseSensitive
		: Qt::CaseInsensitive;

	QRegExp regExp(m_pattemLineEdit->text(), caseSensitivity, syntax);
	m_proxyModel->setFilterRegExp(regExp);


}



void Widget::SortSensitiveChanged()
{
	m_proxyModel->setSortCaseSensitivity(m_sensitiveFilter->isChecked() ? Qt::CaseSensitive
		: Qt::CaseInsensitive);
}

void Widget::FilterColumnChanged()
{
	m_proxyModel->setFilterKeyColumn(m_columnCombo->currentIndex());
}
