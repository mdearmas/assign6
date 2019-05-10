#include "Sorting.h"

void Sorting::bubbleSort(double a[], int size)
{
  double temp;
  for(int i = 0; i < size-1; ++i)
  {
    for(int j = 0; j < size-i-1; ++j)
    {
      if(a[j] > a[j+1])
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
  for(int j = 1; j < size; j++)
  {
    double temp = a[j]; //store marked item
    int k = j; //where to start shifting
    //while the thing to the left is larger, shift
    while(k > 0 && a[k-1] >= temp)
    {
      a[k] = a[k-1];
      k--;
    }
    a[k] = temp; //put marked item in right spot
  }
}

void Sorting::mergeSort(double a[], int low, int high)
{
  if(low < high)
  {
    int middle = (low + high) / 2;
    mergeSort(a, low, middle);
    mergeSort(a, middle+1, high);
    merge(a, low, middle, high);
  }
}

void Sorting::merge(double a[], int low, int middle, int high)
{
  int left_size = middle - low + 1;
  int right_size = high - middle;

  double left_array[left_size];
  int left_index = 0;

  double right_array[right_size];
  int right_index = 0;

  int merged_index = low;

  for(int i = 0; i < left_size; ++i)
  {
    left_array[i] = a[low+i];
  }
  for(int j = 0; j < right_size; ++j)
  {
    right_array[j] = a[middle + 1 + j];
  }

  while(left_index < left_size && right_index < right_size)
  {
    if(left_array[left_index] <= right_array[right_index])
    {
      a[merged_index] = left_array[left_index];
      left_index++;
    }
    else
    {
      a[merged_index] = right_array[right_index];
      right_index++;
    }
    merged_index++;
  }

  while(left_index < left_size)
  {
    a[merged_index] = left_array[left_index];
    left_index++;
    merged_index++;
  }

  while(right_index < right_size)
  {
    a[merged_index] = right_array[right_index];
    right_index++;
    merged_index++;
  }
}

void Sorting::printArray(double a[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

double* Sorting::copyArray(double a[], int size)
{
  double *copy = new double[size];
  for(int i = 0; i < size; ++i)
  {
    copy[i] = a[i];
  }
  return copy;
}
