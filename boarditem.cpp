#include "boarditem.h"

boardItem::boardItem(QObject *parent)
{
    Q_UNUSED(parent);
}

boardItem::boardItem(int itemType, double itemOpacity, int rowInModel) : m_itemType(itemType), m_itemOpacity(itemOpacity), m_rowInModel(rowInModel)
{

}

int boardItem::getItemType() const
{
    return m_itemType;
}

double boardItem::getItemOpacity() const
{
    return m_itemOpacity;
}

int boardItem::getRowInModel() const
{
    return m_rowInModel;
}

void boardItem::setItemType(int type)
{
    m_itemType = type;
    emit itemTypeChanged();
}

void boardItem::setItemOpacity(int opacity)
{
    m_itemOpacity = opacity;
    emit itemOpacityChanged();
}

