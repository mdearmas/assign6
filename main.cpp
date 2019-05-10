#include <iostream>
#include <fstream>
#include <ctime>

#include "Sorting.h"

using namespace std;

int main (int argc, char **argv)
{
  Sorting sort;

  clock_t starting_time, ending_time;

  ifstream input_file;
  double *master_array, *array_copy1, *array_copy2, *array_copy3;
  int index = 0;
  int master_array_size;

  bool first_line = true;
  string filepath, line;

  cout << "Please enter your file name: ";
  cin >> filepath;

  input_file.open(filepath);

  if(input_file.is_open())
  {
    try
    {
      while(getline(input_file, line))
      {
        if(first_line)
        {
          master_array_size = stoi(line);
          master_array = new double[master_array_size];
          first_line = false;
        }
        else
        {
          if(index > master_array_size)
          {
            cout << "ERROR: There are more inputs than indicated. Exiting program." << endl;
            return 0;
          }
          master_array[index] = stod(line);
          index++;
        }
      }
    }
    catch(const invalid_argument& ia)
    {
      cout << "ERROR: There was an invalid entry in your file. The program will now exit. " << endl;
      return 0;
    }

    if(index < master_array_size)
    {
      cout << "ERROR: There were less inputs than indicated. Exiting program." << endl;
      return 0;
    }

    array_copy1 = sort.copyArray(master_array, master_array_size);
    array_copy2 = sort.copyArray(master_array, master_array_size);
    array_copy3 = sort.copyArray(master_array, master_array_size);

    starting_time = clock();
    cout << "Started BubbleSort at " << starting_time << " // ";
    sort.bubbleSort(array_copy1, master_array_size);
    ending_time = clock();
    cout << "Ended BubbleSort at " << ending_time << endl;

    starting_time = clock();
    cout << "Started InsertionSort at " << starting_time << " // ";
    sort.insertionSort(array_copy2, master_array_size);
    ending_time = clock();
    cout << "Ended InsertionSort at " << ending_time << endl;

    starting_time = clock();
    cout << "Started MergeSort at " << starting_time << " // ";
    sort.mergeSort(array_copy3, 0, master_array_size);
    ending_time = clock();
    cout << "Ended MergeSort at " << ending_time << endl;

    input_file.close();
  }
  else
  {
    cout << "ERROR: File was unable to be opened. Exiting program. " << endl;
  }
  return 0;
}
