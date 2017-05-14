

#include "sorttester.h"

#define NBTHREADS 2
#define TABSIZE 100

int main(int argc, char *argv[])
{
    SortTester tester;
    tester.test(TABSIZE, NBTHREADS);
}
