#ifndef BOARDITEM_H
#define BOARDITEM_H

#include <QObject>

class boardItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int itemType READ getItemType WRITE setItemType NOTIFY itemTypeChanged)
    Q_PROPERTY(double itemOpacity READ getItemOpacity WRITE setItemOpacity NOTIFY itemOpacityChanged)

public:
    explicit boardItem(QObject *parent = 0);
    boardItem(int itemType, double itemOpacity, int rowInModel);
    int getItemType() const;
    void setItemType(int type);
    void setItemOpacity(int opacity);
    double getItemOpacity() const;
    Q_INVOKABLE int getRowInModel()const;
signals:
    void itemTypeChanged();
    void itemOpacityChanged();
private:
    int m_itemType;
    double m_itemOpacity;
    int m_rowInModel;
};

#endif // BOARDITEM_H
