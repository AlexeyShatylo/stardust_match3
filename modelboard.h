#ifndef MODELBOARD_H
#define MODELBOARD_H
#include "boarditem.h"
#include <QAbstractListModel>
#include <QVector>
#include <QObject>
#include <QModelIndex>
#include <QList>
#include "modelcolumn.h"
class ModelBoard : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModelBoard(QObject *parent = 0);
    ModelBoard(int width, int height, QVector<int> types);
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    enum columnRoles{columnRole = Qt::UserRole + 1 };
private:
    QVector<ModelColumn*> m_board;
    int m_width;
    int m_height;
    QVector<int> m_types;
};

#endif // MODELBOARD_H
