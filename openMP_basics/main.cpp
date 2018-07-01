#include "omp.h"
#include <stdio.h>

/*
 * OpenMP is a multithreading API
 */

int main(void) {
  #pragma omp parallel
  printf("thread %d\n", omp_get_thread_num());
}

