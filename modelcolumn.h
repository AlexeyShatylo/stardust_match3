#ifndef MODELCOLUMN_H
#define MODELCOLUMN_H
#include "boarditem.h"
#include <QAbstractListModel>
#include <QVector>
#include <QObject>
#include <QModelIndex>
#include <QList>
class ModelColumn : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModelColumn(QObject* parent = 0);
    ModelColumn(int height, QVector<int>types, int itemPositionInModel);
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    enum itemRoles{itemTypeRole = Qt::UserRole + 1, itemOpacityRole = Qt::UserRole + 2, itemPositionInModelRowRole = Qt::UserRole + 3};
    bool create();
    void remove();
    void fillRandomly();
    int getRandomNumber(const int Min, const int Max);
    Q_INVOKABLE QString getSource(int type);
    QList<boardItem *> *getColumn();
private:
   int m_height;
   int m_itemPositionInModelRow;
   QVector<int> m_types;
   QList<boardItem*> m_column;
   boardItem* m_columnItem;

};

#endif // MODELCOLUMN_H
