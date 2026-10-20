#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  const int upperBound = 100000;
  const long randLimit = 10000000;

  int numbers[upperBound];
  int index = 0;
  int rNum = 1;
  int targetValue;
  bool found = false;
  srand(time(NULL));

  for (int i = 0; i < upperBound; i++) {
    rNum = rand() % randLimit;
    numbers[i] = rNum;
  }

  // Worst-Case Scenario
  targetValue = numbers[upperBound - 1];
  clock_t start = clock();

  while ((found == false) && (index < upperBound)) {
    if (targetValue == numbers[index]) {
      found = true;
    } else {
      index++;
    }
  }

  clock_t end = clock();

  if (found == true) {
    printf("Number found at index %d \n", index);
  } else {
    printf("Target not found \n");
  }

  double time_elapsed = ((double)(end - start) / CLOCKS_PER_SEC);
  printf("Time Elapsed, %f\n", time_elapsed);

  return 0;
}
