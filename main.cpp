#include <QCoreApplication>
#include <QtGlobal>
#include <QMessageLogContext>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>

static QString path="D:\\Program\\QT\\log\\log.txt";

void func(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString log;
    QMutex lock;
    switch(type)
    {
    case QtDebugMsg:
        log=msg;
        break;
    case QtInfoMsg:break;
    case QtWarningMsg:break;
    case QtCriticalMsg:break;
    case QtFatalMsg:break;
    }
    lock.lock();
    QFile file(path);
    if (file.open(QFile::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
         out<<log;
    }
    file.close();
    lock.unlock();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInstallMessageHandler(func);
    qDebug()<<"fuck";
    return 0;
}
