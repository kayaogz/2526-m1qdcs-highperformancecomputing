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

#pragma omp parallel default(none) num_threads(4) shared(two, three, four, nine)
  {
    int thid = omp_get_thread_num();
    printf("thid = %d\n", thid);
#pragma omp sections
    {
#pragma omp section
      {
        printf("four is computed by = %d\n", thid);
        four = computeFour();
#pragma omp atomic
        nine = nine + four;
      }
#pragma omp section
      {
        printf("three is computed by = %d\n", thid);
        three = computeThree();
#pragma omp atomic
        nine = nine + three;
      }
#pragma omp section
      {
        printf("two is computed by = %d\n", thid);
        two = computeTwo();
#pragma omp atomic
        nine = nine + two;
      }
    }
  }

  printf("nine = %d\n", nine);

  return 0;
}
