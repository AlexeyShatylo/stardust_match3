#include "modelcolumn.h"
#include <QDebug>
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
bool ModelColumn::create()
{
    return true;
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
    else if (index.row() < 0 || index.row() >= m_column.size()){
          return QVariant();
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

bool ModelColumn::makeWay(int index)
{
    if(m_path.isEmpty()) {
        m_path.append(index);
    }
    else
    {
        if(m_path[0]!= index) {
            m_path.append(index);
            qDebug() << m_path;
            return true;
        }
        else {
            m_path.clear();
        }
    }
    return false;
}
bool ModelColumn::moveItemVectical(int from , int to)
{

    beginMoveRows(QModelIndex(), from, from, QModelIndex(), to + 1);
    endMoveRows();
    qSwap(m_column[from],m_column[from]);
}

bool ModelColumn::moveItemHorizontal(int from, int to)
{
    beginMoveRows(QModelIndex().parent(), from, from, QModelIndex().child(0,0), to + 1);
    endMoveRows();

}
void ModelColumn::shiftingItems (int index)
{
    if(makeWay(index)) {
        if(m_path[0] - m_path[1] == 1 || m_path[0] - m_path[1] == -1) {
            if(m_path[0] - m_path[1] == - 1) {
                moveItemVectical(m_path[0],m_path[1]);
            }
            else if(m_path[0] - m_path[1]  == 1) {
                moveItemVectical(m_path[1], m_path[0]);
            }
        }
        m_path.clear();
    }
}

