#ifndef SORTTESTER_H
#define SORTTESTER_H

#include <QtGlobal>

class SortTester
{
public:
    SortTester();

    void test(qint64 tabSize, int nbThreads);
};

#endif // SORTTESTER_H
