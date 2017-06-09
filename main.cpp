#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "cppSource/colorMaker/colormaker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 注册QML类型
    qmlRegisterType<ColorMaker>("veiko.qt.ColorMaker",1,0,"ColorMaker");

    // QML上下文开始,QML类型的注册必须放在此之前
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

