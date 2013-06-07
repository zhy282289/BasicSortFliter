#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	MyModel(QObject *parent);
	~MyModel();

protected:
	Qt::ItemFlags	flags ( const QModelIndex & index ) const;
	QVariant	data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
	int	rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	int	columnCount ( const QModelIndex & parent = QModelIndex() ) const;


private:
	QList<QStringList> m_list;
};

#endif // MYMODEL_H
