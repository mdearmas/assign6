/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 6: Sorting
Purpose: This file, main.cpp, runs the different sorting tests. It takes a file, creates an array (and three other copies),
sorts them using various different algorithms, then prints out the time taken for each sorting algorithm.
*/

#include <iostream>
#include <fstream> //allows access to file input/output
#include <ctime> //allows access to the C time class

#include "Sorting.h" //allows access to the Sorting class

using namespace std;

int main (int argc, char **argv)
{
  Sorting sort;

  clock_t starting_time, ending_time; //used to keep track of the starting and ending clock tick numbers

  ifstream input_file;
  double *master_array, *array_copy1, *array_copy2, *array_copy3; //the master array generated from the file and its three copies for sorting
  int index = 0; //where to insert the next element while reading through the file
  int master_array_size; //stores the size of the array for reference

  bool first_line = true; //since the first line of the file is the size, we need to keep track of it
  string filepath, line;

  cout << "Please enter your file name: ";
  cin >> filepath;

  input_file.open(filepath);

  if(input_file.is_open()) //ensures file is opened successfully
  {
    try
    {
      while(getline(input_file, line)) //while the file has contents
      {
        if(first_line) //if it is the first line
        {
          master_array_size = stoi(line); //store the size of the array
          master_array = new double[master_array_size]; //initialize array
          first_line = false; //switch bool to false
        }
        else
        {
          if(index > master_array_size) //if the size is smaller than the actual number of inputs, print an error and end program early
          {
            cout << "ERROR: There are more inputs than indicated. Exiting program." << endl;
            return 0;
          }
          master_array[index] = stod(line); //convert line to double and then add to array
          index++;
        }
      }
    }
    catch(const invalid_argument& ia) //if the program encounters a non-double in the file, print an error and end program early
    {
      cout << "ERROR: There was an invalid entry in your file. The program will now exit. " << endl;
      return 0;
    }

    if(index < master_array_size) //if the size was larger than the number of elements, print an error and end program early
    {
      cout << "ERROR: There were less inputs than indicated. Exiting program." << endl;
      return 0;
    }

    //making copies of the array for analysis
    array_copy1 = sort.copyArray(master_array, master_array_size);
    array_copy2 = sort.copyArray(master_array, master_array_size);
    array_copy3 = sort.copyArray(master_array, master_array_size);

    //BubbleSort Test
    starting_time = clock();
    cout << "Started BubbleSort at " << starting_time << " // ";
    sort.bubbleSort(array_copy1, master_array_size);
    ending_time = clock();
    cout << "Ended BubbleSort at " << ending_time << " (Total time: " << ending_time-starting_time << ")" << endl;

    //InsertionSort Test
    starting_time = clock();
    cout << "Started InsertionSort at " << starting_time << " // ";
    sort.insertionSort(array_copy2, master_array_size);
    ending_time = clock();
    cout << "Ended InsertionSort at " << ending_time << " (Total time: " << ending_time-starting_time << ")" << endl;

    //MergeSort Test
    starting_time = clock();
    cout << "Started MergeSort at " << starting_time << " // ";
    sort.mergeSort(array_copy3, 0, master_array_size);
    ending_time = clock();
    cout << "Ended MergeSort at " << ending_time << " (Total time: " << ending_time-starting_time << ")" << endl;

    //QuickSort Test
    starting_time = clock();
    cout << "Started QuickSort at " << starting_time << " // ";
    sort.quickSort(master_array, 0, master_array_size);
    ending_time = clock();
    cout << "Ended QuickSort at " << ending_time << " (Total time: " << ending_time-starting_time << ")" << endl;

    //deallocate the space taken by the arrays
    delete[] master_array;
    delete[] array_copy1;
    delete[] array_copy2;
    delete[] array_copy3;

    input_file.close(); //close file
  }
  else //if the file was not opened successfully
  {
    cout << "ERROR: File was unable to be opened. Exiting program. " << endl;
  }

  return 0;
}
