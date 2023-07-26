#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define LEN 64


void quickFind(void);
void quickUnion(void);
void printArr(int *arr, int size);

int main(void) {
  /** Give the output that a connectivity algorithm should produce when given the input:
   *  0-2, 1-4, 2-5, 3-6, 0-4, 6-0, 1-3
   *
   *  Given    Output     Total Connections
   *  0-2      0-2        0-2
   *  1-4      1-4        1-4
   *  2-5      2-5        (0-2) (2-5)
   *  3-6      3-6        3-6
   *  0-4      0-4        (0-4) (4-1) (0-2) (2-5)
   *  6-0      6-0        (6-0) (6-3) (0-4) (0-2) (4-1) (2-5)
   *  1-3      1-4-0-6-3  (1-3) (4-1) (6-3) (0-4) (6-0) (0-2) (2-5)
   */

  printf("Running quickFind()\n");
  quickFind();
  printf("\n\nRunning quickUnion()\n");
  quickUnion();
  return EXIT_SUCCESS;
}


void quickFind(void) {
  int i, j;           // Index pointers
  int p, q;           // User-entered connectivity pairs
  int temp;           // Temporary number for re-assigning values based on pair
  int numInput;       // Used to determine if the user entered a valid pair
  char *cPtr;         // Used for entering a null char at the end of the user entry
  int arr[N];         // Array of integers representing connections
  char line[LEN];     // Holds user-entered text

  // Initialize the integer array so each element is its index
  for (i = 0; i < N; i++) {
    arr[i] = i;
  }

  while (1) {
    printArr(arr, N);
    do {
      //printf("Enter values for p and q (or -1 to quit): ");  // p and q must be < 10
      fgets(line, LEN, stdin);
      p = 0;
      q = 0;
      cPtr = strchr(line, '\n');
      if (cPtr != NULL)
	*cPtr = '\0';
      numInput = sscanf(line, "%d %d", &p, &q);
      if (p < 0) {
	printArr(arr, N);
        return;
      }
    } while (numInput != 2);
    temp = arr[p];
    for (j = 0; j < N; j++) {
      if (arr[j] == temp)
	arr[j] = arr[q];
    }
    printf("p: %d, q: %d\n", p, q);
  }
  printArr(arr, N);
}

// Prints an array
void printArr(int *arr, int size) {
  int i, num;
  
  printf("\t[");
  for (i = 0; i < size; i++) {
    num = arr[i];
    if (i == size - 1)
      printf("%d]\n", num);
    else
      printf("%d, ", num);
  }
}


void quickUnion(void) {
  int i, j;
  int p, q;
  int numInput;
  int arr[N];
  char *cPtr;
  char line[LEN];

  for (i = 0; i < N; i++) {
    arr[i] = i;
  }

  while (1) {
    printArr(arr, N);
    do {
      // printf("Enter p and q (or -1 to quit): ");
      fgets(line, LEN, stdin);
      p = 0;
      q = 0;
      cPtr = strchr(line, '\n');
      if (cPtr != NULL)
	*cPtr = '\0';
      numInput = sscanf(line, "%d %d", &p, &q);
      if (p < 0) {
	printArr(arr, N);
	return;
      }
    } while (numInput != 2);
    for (i = p; i != arr[i]; i = arr[i]);
    for (j = q; j != arr[j]; j = arr[j]);
    if (i == j)
      continue;
    arr[i] = j;
    printf("p: %d, q: %d\n", p, q);
  }
}
