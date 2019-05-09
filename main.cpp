#include <iostream>
#include <fstream>

#include "Sorting.h"

using namespace std;

int main (int argc, char **argv)
{
  Sorting sort;

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
          master_array[index] = stod(line);
          index++;
        }
      }
    }
    catch(const out_of_range& oor)
    {
      cout << "There was an invalid entry in your file. The program will now exit. " << endl;
      return 0;
    }

    array_copy1 = sort.copyArray(master_array, master_array_size);
    array_copy2 = sort.copyArray(master_array, master_array_size);
    array_copy3 = sort.copyArray(master_array, master_array_size);

    sort.printArray(master_array, master_array_size);
    sort.printArray(array_copy1, master_array_size);
    sort.printArray(array_copy2, master_array_size);
    sort.printArray(array_copy3, master_array_size);

    input_file.close();
  }
  else
  {
    cout << "File was unable to be opened. Exiting program. " << endl;
  }
  return 0;
}
