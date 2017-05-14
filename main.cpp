

#include "sorttester.h"

#define NBTHREADS 4
#define TABSIZE 1000

int main(int argc, char *argv[])
{
    SortTester tester;
    tester.test(TABSIZE, NBTHREADS);
}
