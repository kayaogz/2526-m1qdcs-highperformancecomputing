#include <cstdio>

int main()
{
  printf("Oh,");

#pragma omp parallel default(none) num_threads(3)
  {
    printf(" no");
  }

  printf("!\n");

  return 0;
}
