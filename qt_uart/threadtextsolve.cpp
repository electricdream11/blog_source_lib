#include "threadtextsolve.h"
#include <QFile>
#include <QDir>
#include <QRegExp>
#include <QDebug>
threadTextSolve::threadTextSolve()
{
    m_toStop=false;
}
void threadTextSolve::run()
{
    QFile fil(QDir::currentPath()+".txt");
    fil.open(QIODevice::ReadOnly);
    char buf[3];
    qint64  addr;
    qint64  length;
    QString buf_exp;
    QRegExp exp("[0-9a-fA-F]");
    addr=0;
    while(!m_toStop)
    {
        fil.seek(addr);
        length = fil.read(buf,sizeof (buf));
        buf_exp = QString::fromLocal8Bit(buf);
        if(! exp.indexIn(buf_exp))
        {
            qDebug()<<buf_exp;
            addr=addr+length;
        }
        else
        {
            qDebug()<<"error";
            addr=addr+1;
        }
        if(addr>=fil.size())
        {
            fil.close();
            m_toStop = true;
        }
    }
}
void threadTextSolve::stop()
{
    m_toStop=true;
}
