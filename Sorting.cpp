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
