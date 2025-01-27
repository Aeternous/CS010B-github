//include any standard libraries needed
#include <iostream>
#include <vector>
#include <string>
#include <fstream> 

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);

const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   if (argc < 2) {
      cerr << "Error: No filename provided." << endl;
      return 1;
   }
   
   // open file and verify it opened
   string fileName = argv[1];
   ifstream inputFile(fileName);

   if (!inputFile) {
      cerr << "Error: Could not open file: " << fileName << endl;
      return 1;
   }

   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];
   int arraySize = 0;

   double tempVal;
   while (inputFile >> tempVal) {
      array[arraySize++] = tempVal;
   }

   inputFile.close();

   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(array, arraySize)  << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index;
   cout << "Enter index of value to be removed (0 to " << arraySize - 1 << "): ";
   cin >> index;

   cout << "Before removing value: ";
   
   // Call the display function to output the array.
   display(array, arraySize);
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(array, arraySize, index);
   
   cout << "After removing value: ";
   
   // Call the display function again to output the array
   // with the value removed.
   display(array, arraySize);

   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(array, arraySize) << endl;
   
   return 0;
}

// Function to calculate the mean
double mean(const double array[], int arraySize) {
   double sum = 0;
   for (int i = 0; i < arraySize; ++i) {
      sum += array[i];
   }
   
   if (arraySize == 0) {
      return 0;
   } else {
      return sum / arraySize;
   }
}

// Function to remove an element at a specific index
void remove(double array[], int &arraySize, int index) {
   if (index >= 0 && index < arraySize) {
      for (int i = index; i < arraySize - 1; ++i) {
         array[i] = array[i + 1];
      } 
      --arraySize;
   }
}

// Function to display the array
void display(const double array[], int arraySize) {
   for (int i = 0; i < arraySize; ++i) {
      cout << array[i];
      if (i < arraySize - 1) {
         cout << ", ";
      }
   }
   cout << endl;
}
