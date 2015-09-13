#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QTime>
#include "dataParser.h"
#include "boarditem.h"
#include "modelcolumn.h"
#include "modelboard.h"
int main(int argc, char *argv[])
{
    qsrand(static_cast<uint>(QTime::currentTime().msec()));
    QApplication app(argc, argv);
    DataParser parser;
    ModelBoard myBoard(parser.getWidth(),parser.getHeighth(),parser.getTypes());
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("myBoardModel", &myBoard);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
