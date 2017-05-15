

#include "sorttester.h"

#define NBTHREADS 3
#define TABSIZE 3000

int main(int argc, char *argv[])
{
    SortTester tester;
    tester.test(TABSIZE, NBTHREADS);
}
