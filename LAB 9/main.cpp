#include <iostream>
#include <string>

using namespace std;


void flipString(string &s){
   if (s.length() <= 1) {
      return;
   }
    char temp = s[0];
    s[0] =s[s.length()-1];
    s[s.length() - 1] = temp;

    string sub = s.substr(1, s.length() - 2);

    flipString(sub);// flips flip string loop
    s = s[0] + sub + s[s.length() - 1];
}


int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

    
