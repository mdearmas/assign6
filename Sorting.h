#ifndef SORTING_H_
#define SORTING_H_

class Sorting {
public:
  Sorting();

  void bubbleSort(int a[]);

  void insertionSort(int a[]);

  //Pseudocode from https://www.geeksforgeeks.org/quick-sort/
  void quickSort(int a[], int low, int high);
  int partition(int arr[], int low, int high);

  void mergeSort(int a[], int low, int high);
  void merge(int a[], int low, int middle, int high);

  void printArray(int a[]);
};

#endif
