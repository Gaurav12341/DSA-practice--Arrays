#include <stdio.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main() { int n;
printf("Enter the size of array: ");
    scanf("%d",&n);
int data[n];
  for (int i = 0; i < n; i++)
  {
      scanf("%d",&data[i]);
  }
  
  insertionSort(data, n);
  printf("Sorted array in ascending order:\n");
  printArray(data, n);
}