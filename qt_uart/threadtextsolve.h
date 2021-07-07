#ifndef THREADTEXTSOLVE_H
#define THREADTEXTSOLVE_H

#include <QThread>

class threadTextSolve : public QThread
{
public:
    threadTextSolve();
protected:
    volatile bool m_toStop;
    void run();
public:
    void stop();

};

#endif // THREADTEXTSOLVE_H
