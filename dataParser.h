#ifndef dataParser_H
#define dataParser_H
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QVector>
#include <QObject>
class DataParser: public QObject
{
public:
    DataParser(QObject *parent = 0);
    ~DataParser();
    int getWidth()const;
    int getHeighth()const;
    int getMinScore()const;
    int getElementScore()const;
    int getMaxMoves()const;
    QVector<int> getTypes()const;
    void fillFromFile();
private:
    int m_width;
    int m_height;
    int m_maxMoves;
    int m_minScore;
    int m_elementScore;
    QVector<int> m_types;
};

#endif // dataParser_H
