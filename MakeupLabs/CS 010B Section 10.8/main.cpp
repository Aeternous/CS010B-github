#include <iostream>
#include <fstream>
using namespace std;


void rCopy(istream &, ostream &);
bool rCopy(const string &, const string &);

int main(int argc, char *argv[]) {

   if (argc != 3) {
      cout << "USAGE: " << argv[0] << " input-file output-file" << endl;
      return 1;
   }

   if (rCopy(argv[1], argv[2])) {
      cout << "Copy completed" << endl;
   } else {
      cout << "Copy not completed" << endl;
   }
   
   return 0;
}



// Implement these functions

void rCopy(istream &in, ostream &out) {
   char ch;
   if(!in.get(ch)){
      return;
   }
   rCopy(in, out);

   out << ch;
}

bool rCopy(const string &in, const string &out) {
   ifstream inFile(in);

   if(!inFile.is_open()){
      cout << "Error opening " << in << endl;
      return false;
   }

   ofstream outFile(out);

   if(!outFile.is_open()){
      cout << "Error opening " << out << endl;
      return false;
   }
   rCopy(inFile, outFile);
   inFile.close();
   outFile.close();

   return true;
   
}
