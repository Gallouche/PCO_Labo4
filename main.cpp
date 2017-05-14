

#include "sorttester.h"

#define NBTHREADS 4
#define TABSIZE 100

int main(int argc, char *argv[])
{
    SortTester tester;
    tester.test(TABSIZE, NBTHREADS);
}
