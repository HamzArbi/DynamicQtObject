#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register a singleton in the QMetaObject to be handled by QML
    qmlRegisterSingletonInstance("Custom", 1, 0, "Control", Controller::i());

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("DynamicQtObject", "Main");

    return app.exec();
}
