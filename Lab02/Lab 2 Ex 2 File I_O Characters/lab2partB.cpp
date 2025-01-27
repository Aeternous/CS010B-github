#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string& fileName, char n);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string& fileName, char n){
   ifstream folderName;
   folderName.open(fileName);
   int count = 0;
   char character;

   if (!folderName.is_open()){
      cout << "Error opening " << fileName << endl;
      exit(EXIT_FAILURE);
   }
   
   while (folderName.get(character)) {
      if (character == n) {
         count++;
      }
   }

   folderName.close();

   //if (character == n){
     // count++;
   //}
   return count;

}