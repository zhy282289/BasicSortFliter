#include "StdAfx.h"
#include "mymodel.h"

MyModel::MyModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	for (int i = 0; i < 100; ++i)
	{
		QStringList list;
		list << QString("Boy%1").arg(i) << QString("Fuck%1").arg(i) << QString("Girl%1").arg(i); 
		m_list.push_back(list);
	}
}

MyModel::~MyModel()
{

}

Qt::ItemFlags MyModel::flags( const QModelIndex & index ) const
{
	Q_UNUSED(index);
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant MyModel::data( const QModelIndex & index, int role /*= Qt::DisplayRole */ ) const
{
	int row = index.row();
	if (!index.isValid() || row > m_list.size() || row < 0)
	{
		return QVariant();
	}

	int column = index.column();
	if (role == Qt::DisplayRole)
	{
		if (column == 0)
		{
			return m_list.at(row).at(0);
		}
		else if (column == 1)
		{
			return m_list.at(row).at(1);
		}
		else if (column == 2)
		{
			return m_list.at(row).at(2);
		}
		else
		{
			return QVariant();
		}
	}
	else if (role == Qt::UserRole + 1)
	{
		QString filterStr = m_list.at(row).at(0) + m_list.at(row).at(1) + m_list.at(row).at(2);
		return filterStr;
	}
	return QVariant();
}

int MyModel::rowCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	Q_UNUSED(parent)
	return m_list.size();
}

int MyModel::columnCount( const QModelIndex & parent /*= QModelIndex() */ ) const
{
	Q_UNUSED(parent)
	return 3;
}
