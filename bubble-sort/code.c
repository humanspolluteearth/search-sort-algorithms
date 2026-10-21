#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const int upperBound = 100000;
  const int randLimit = 10000;

  int numbers[upperBound];
  int index = 0;
  int limit = upperBound;
  int temp;
  bool sorted = false;

  srand(time(NULL));
  for (int i = 0; i < upperBound; i++) {
    numbers[i] = rand() % randLimit;
  }

  clock_t start = clock();

  while (sorted == false) {
    sorted = true;
    for (int i = 0; i < limit - 1; i++) {
      if (numbers[i] > numbers[i + 1]) {
        temp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = temp;

        sorted = false;
      }
    }
    limit = limit - 1;
  }

  clock_t end = clock();
  double time_elapsed = ((double)(end - start) / CLOCKS_PER_SEC);

  for (int i = 0; i < upperBound; i++) {
    printf("%d\n", numbers[i]);
  }

  printf("Time Elapsed: %f \n", time_elapsed);

  return 0;
}
