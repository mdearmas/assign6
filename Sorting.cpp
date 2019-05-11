/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 6: Sorting
Purpose: This file, Sorting.cpp, contains the out-of-class member functions of the Sorting class.
*/

#include "Sorting.h"

void Sorting::bubbleSort(double a[], int size)
{
  double temp; //to store double for swap
  for(int i = 0; i < size-1; ++i) //iterate through the entire array
  {
    for(int j = 0; j < size-i-1; ++j) //iterate through the first size-i-1 elements, as the last i elements have already found their place
    {
      if(a[j] > a[j+1]) //if the element at the right is less than the current element, swap
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

void Sorting::insertionSort(double a[], int size)
{
  for(int j = 1; j < size; ++j)
  {
    double temp = a[j]; //store marked item
    int k = j; //where to start shifting

    while(k > 0 && a[k-1] >= temp) //while the element to the left is larger, shift
    {
      a[k] = a[k-1];
      k--;
    }

    a[k] = temp; //put marked item in right spot
  }
}

void Sorting::quickSort(double a[], int low, int high)
{
  if(low < high) //checks if the lower bound of the sort is actually less than the higher bound
  {
    int pivot = partition(a, low, high); //sets a[high] as the pivot point and partitions accordingly, then returns the new index of the pivot

    quickSort(a, low, pivot-1); //recursively calls quickSort on everything to the left of the pivot
    quickSort(a, pivot+1, high); //recursively calls quickSort on everything to the right of the pivot
  }
}

int Sorting::partition(double a[], int low, int high)
{
  int pivot = a[high]; //sets the last element as the pivot
  int small_index = low - 1; //used to keep track of where all the elements smaller than the pivot point are
  double temp; //stores elements for swapping

  for(int j = low; j <= high-1; ++j) //iterates through array
  {
    if(a[j] <= pivot) //if the element is smaller than the pivot point, move to the left half
    {
      small_index++;
      temp = a[small_index];
      a[small_index] = a[j];
      a[j] = temp;
    }
  }

  //moves the pivot point to its appropriate location in the array
  temp = a[small_index+1];
  a[small_index+1] = a[high];
  a[high] = temp;

  return (small_index+1); //returns new index of pivot point
}

void Sorting::mergeSort(double a[], int low, int high)
{
  if(low < high) //checks if the lower bound of the sort is actually less than the higher bound
  {
    int middle = (low + high) / 2; //finds the middle index of the array
    mergeSort(a, low, middle); //recurvisely calls mergeSort on the left half of the array
    mergeSort(a, middle+1, high); //recursively calls mergeSort on the right half of the array
    merge(a, low, middle, high); //merges the two halves of the array together
  }
}

void Sorting::merge(double a[], int low, int middle, int high)
{
  int left_size = middle - low + 1; //finds the size of the left half of the array
  int right_size = high - middle; //finds the size of the right half of the array

  double left_array[left_size]; //creates a new array to serve as the copy of the left half
  int left_index = 0;

  double right_array[right_size]; //creates a new array to serve as the copy of the right half
  int right_index = 0;

  int merged_index = low; //this is where the merge starts

  for(int i = 0; i < left_size; ++i) //copies the left half of the array
  {
    left_array[i] = a[low+i];
  }

  for(int j = 0; j < right_size; ++j) //copies the right half of the array
  {
    right_array[j] = a[middle + 1 + j];
  }

  while(left_index < left_size && right_index < right_size) //while there are still elements in BOTH the left and right arrays
  {
    if(left_array[left_index] <= right_array[right_index]) //if next element in the left array is less than or equal to next element in right array
    {
      a[merged_index] = left_array[left_index]; //add left element to the merged array
      left_index++; //increment index
    }
    else //if next element in right array is less than next element in left array
    {
      a[merged_index] = right_array[right_index]; //add right element to the merged array
      right_index++; //increment index
    }
    merged_index++; //increment to find next index to merge
  }

  while(left_index < left_size) //after exiting the loop, if there are still elements left in the left half, add them to the merged array
  {
    a[merged_index] = left_array[left_index];
    left_index++;
    merged_index++;
  }

  while(right_index < right_size) //after exiting the loop, if there are still elements left in the right half, add them to the merged array
  {
    a[merged_index] = right_array[right_index];
    right_index++;
    merged_index++;
  }
}

void Sorting::printArray(double a[], int size) //prints all the elements of an array, used during testing
{
  for(int i = 0; i < size; ++i)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

double* Sorting::copyArray(double a[], int size) //takes in an array and outputs a copy of said array
{
  double *copy = new double[size];
  for(int i = 0; i < size; ++i)
  {
    copy[i] = a[i];
  }
  return copy;
}
