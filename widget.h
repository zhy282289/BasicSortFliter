#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#define QSTR(s) QString::number(s)

class MyModel;
class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

private:
	void	CreateUi();
	void	CreateSourceModel(QStandardItemModel *model);
	void	AddModelItem(QStandardItemModel *model, const QString &s1,const QString &s2,const QString &s3 );

private slots:
	void	FilterChanged();
	void	FilterColumnChanged();
	void	SortSensitiveChanged();

private:
	
	QGroupBox	*m_sourceGroupBox;
	QGroupBox	*m_proxyGroupBox;

	QTableView	*m_sourceView;
	QTableView	*m_proxyView;

	QStandardItemModel	*m_sourceModel;
	QSortFilterProxyModel	*m_proxyModel;

	QLineEdit	*m_pattemLineEdit;
	QComboBox	*m_syntaxCombo;
	QComboBox	*m_columnCombo;

	QCheckBox	*m_sensitiveFilter;
	QCheckBox	*m_sensitiveSort;

	MyModel *m_myModel;
};

#endif // WIDGET_H
