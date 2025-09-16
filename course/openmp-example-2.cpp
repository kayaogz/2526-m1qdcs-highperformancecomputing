#include <cstdio>
#include "unistd.h"
#include "omp.h"

int computeTwo()
{
  sleep(2);
  return 2;
}

int computeThree()
{
  sleep(3);
  return 3;
}

int computeFour()
{
  sleep(4);
  return 4;
}

int main()
{
  int two = 0, three = 0, four = 0, nine = 0;

#pragma omp parallel default(none) num_threads(2) shared(two, three, four)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();
    printf("I am thread %d/%d\n", thid, numth);

    if (thid == 0) {
      two = computeTwo();
    }

    if (thid == 1) {
      three = computeThree();
    }

    if (thid == 2) {
      four = computeFour();
    }
  }


  nine = two + three + four;

  printf("nine = %d\n", nine);

  return 0;
}
