#include "modelboard.h"

ModelBoard::ModelBoard(QObject *parent): QAbstractListModel(parent)
{
}

ModelBoard::ModelBoard(int width, int height, QVector<int> types):m_width(width),m_height(height),m_types(types)
{
    for(int i = 0; i < m_width; i++)
    {
        m_board.append(new ModelColumn(m_height,m_types,i));
    }
}

QVariant ModelBoard::data(const QModelIndex &index, int role) const
{
    ModelColumn* m_column = m_board[index.row()];
    if(role == columnRole) {
        return QVariant::fromValue<QObject *>(m_column);
    }
    return 0;
}

int ModelBoard::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_board.size();

}

QHash<int, QByteArray> ModelBoard::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[columnRole] = "column";
    return roles;
}

