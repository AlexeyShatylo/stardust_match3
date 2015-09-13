#include "modelcolumn.h"

ModelColumn::ModelColumn(QObject *parent): QAbstractListModel(parent)
{

}
ModelColumn::ModelColumn(int height, QVector<int> types,int itemPositionInModel):m_height(height), m_types(types), m_itemPositionInModelRow(itemPositionInModel)
{
    for(int i = 0; i < m_height; i++) {
        m_column.append(new boardItem(0,0,itemPositionInModel));
    }
    fillRandomly();
}
void ModelColumn::remove()
{
    delete[] m_columnItem;
}
void ModelColumn::fillRandomly()
{
    QVector<int> randVect;
    while(randVect.size() < m_height){
        int  temp = getRandomNumber(0, m_types.size() - 1);
        randVect.append(temp);
    }
    for(int i = 0; i < randVect.size(); i++) {
        m_column[i]->setItemType(randVect[i]);
        m_column[i]->setItemOpacity(1);
    }
}

int ModelColumn::ModelColumn::getRandomNumber(const int Min, const int Max)
{
    return ((qrand() % ((Max + 1) - Min)) + Min);
}

QVariant ModelColumn::data(const QModelIndex &index, int role) const
{
    const boardItem* m_columnItem = m_column[index.row()];

    if(role == itemTypeRole) {
        return m_columnItem->getItemType();
    }
    else if(role == itemOpacityRole) {
        return m_columnItem->getItemOpacity();
    }
    else if(role == itemPositionInModelRowRole) {
        return m_columnItem->getRowInModel();
    }
    return 0;
}
QHash<int, QByteArray> ModelColumn::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[itemTypeRole] = "itemType";
    roles[itemOpacityRole] = "itemOpacity";
    roles[itemPositionInModelRowRole] = "positionInModelRowRole";
    return roles;
}

int ModelColumn::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  m_column.size();
}
QString ModelColumn::getSource(int type)
{
    switch (type) {
    case 0:
        return "qrc:/img_clock.png";
        break;
    case 1:
        return "qrc:/img_compas.png";
        break;
    case 2:
        return "qrc:/img_lamp.png";
        break;
    case 3:
        return "qrc:/img_tetris.png";
        break;
    case 4:
        return "qrc:/img_vinil.png";
        break;
    default:
        break;
    }
    return "noImage";
}

void ModelColumn::shiftingItemVertical(int index)
{
    if(makeWay(index)) {
        if(m_path[0] - m_path[1] == - 1)
        {
            beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] + 2);
            qSwap(m_column[m_path[0]], m_column[m_path[1]]);
            endMoveRows();
        } else if (m_path[0] - m_path[1] == 1) {
            beginMoveRows(QModelIndex(), m_path[0], m_path[0], QModelIndex(), m_path[0] - 1);
            qSwap(m_column[m_path[0]], m_column[m_path[1]]);
            endMoveRows();
        }

        m_path.clear();
    }
}
bool ModelColumn::makeWay(int index)
{
    if(m_path.empty()) {
        m_path.append(index);
        return false;
    } else {
        if(index == m_path[0]) {

            return false;
        } else {
            m_path.append(index);
            return true;
        }
    }
    return false;
}

