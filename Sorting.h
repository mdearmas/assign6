/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 6: Sorting
Purpose: This file, Sorting.h, contains the class definition for Sorting, which controls all interactions with the requested array.
Included are the necessary functions for BubbleSort, InsertionSort, QuickSort, and MergeSort, as well as auxillary functions for
copying and printing arrays to help with testing.
*/

#ifndef SORTING_H_
#define SORTING_H_

#include <iostream>

using namespace std;

class Sorting {
public:
  Sorting() {}; //default constructor, left empty because there are no member variables to initialize

  void bubbleSort(double a[], int size); //compares two adjacent numbers, swaps if necessary, then continues iterating

  void insertionSort(double a[], int size); //finds a marker, then inserts the marker into the proper place by shifting elements down

  //Pseudocode from https://www.geeksforgeeks.org/quick-sort/
  void quickSort(double a[], int low, int high); //recursively sorts around a pivot point
  int partition(double a[], int low, int high); //chooses the last element as the pivot, then puts all elements smaller than the pivot to the left and all elements greater than the pivot to the right

  //Pseudocode from in-class implementation and https://www.geeksforgeeks.org/merge-sort/
  void mergeSort(double a[], int low, int high); //recursively divides an array into two halves and sorts them
  void merge(double a[], int low, int middle, int high); //makes copies of the left and right halves of the passed array, sorts the elements, then merges them back together

  void printArray(double a[], int size); //prints all the elements of an array, used during testing

  double* copyArray(double a[], int size); //takes in an array and outputs a copy of said array
};

#endif
