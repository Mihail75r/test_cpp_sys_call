#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    int fd = 0;
    fd = open("/dev/video0", O_RDONLY);
    qDebug() << fd;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
