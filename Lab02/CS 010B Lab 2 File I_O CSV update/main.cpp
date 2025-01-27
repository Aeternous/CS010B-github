#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFs(inputFile);
   // Verify file opened correctly.
   if (!inFs.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Read in integers from input file to vector.
   vector<int> vect;
   int currNum = 0;
   char trash = 0;
   while(inFs >> currNum) {
      inFs >> trash;
      vect.push_back(currNum);
   }
   // Close input stream.
   inFs.close();
   // Get integer average of all values read in.
   int sum = 0;
   int count = 0;
   for (unsigned int i = 0; i < vect.size(); ++i){
      sum += vect[i];
      count++;
   }

   int avg = sum / count;
   vector<int> newVect;
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < vect.size(); ++i){
      vect[i] = vect[i] - avg;
      newVect.push_back(vect[i]);
   }
   // Create output stream and open/create output csv file.
   ofstream outFS(outputFile);
   // Verify file opened or was created correctly.
   if(!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned int i = 0; i < newVect.size(); ++i){
      outFS << newVect[i];
      if(i != newVect.size() - 1){
         outFS << trash;
      }
   }
   
   // Close output stream.
   outFS.close();

   return 0;
}