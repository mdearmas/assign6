#ifndef SORTING_H_
#define SORTING_H_

#include <iostream>

using namespace std;

class Sorting {
public:
  Sorting() {}; //default constructor, left empty because there are no member variables to initialize

  void bubbleSort(double a[], int size);

  void insertionSort(double a[], int size);

  //Pseudocode from https://www.geeksforgeeks.org/quick-sort/
  void quickSort(double a[], int low, int high);
  int partition(double a[], int low, int high);

  void mergeSort(double a[], int low, int high);
  void merge(double a[], int low, int middle, int high);

  void printArray(double a[], int size);

  double* copyArray(double a[], int size);
};

#endif
