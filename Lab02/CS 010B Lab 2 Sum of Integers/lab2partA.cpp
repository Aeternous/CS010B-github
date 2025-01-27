#include <fstream>
#include <iostream>
#include <cstdlib> // needed for exit function
#include <string>  // needed for std::string

using namespace std;

int fileSum(const string& fileName);

int main() {
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(const string& fileName) {
   ifstream folderName;
   folderName.open(fileName);
   int sum = 0;
   int num;

   if (!folderName.is_open()) {
      cout << "Error opening " << fileName << endl;
      exit(EXIT_FAILURE); 
   }

   while (folderName >> num) {
      sum += num;
   }

   folderName.close();

   return sum;
}
