#include <cstdio>
#include <vector>
#include "unistd.h"
#include "omp.h"

#define MAX_THREADS 1000


int main()
{
  int N = 16;
  int sum = 0;
  std::vector<int> A(N);

#pragma omp parallel default(none) num_threads(2) shared(A, sum, N)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();

    printf("thid = %d, numth = %d\n", thid, numth);

#pragma omp for
    for (int i = 0; i < N; i++) {
      printf("i %d, thid %d\n", i, thid);
      A[i] = i;
    }
  }

//  for (int i = 0; i < N; i++) {
//    printf("%d ", A[i]);
//  }
//  printf("\n");

  return 0;
}
