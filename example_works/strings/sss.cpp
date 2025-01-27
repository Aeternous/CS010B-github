#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    string s1 = "data1.txt";
    string s2 = "data2.txt";

    ifstream inFs(s1);
    inFs.open(s1);

    if(!inFs.is_open()){
        cout << "Nigga use ur eyes shit, it aint opening: " << s1 << endl;
        return 1;
    }
    
    while(!inFs.fail()){
        inFs >> s1 >> s2;
    }
    while(!inFs.eof()){
        cout << "Failure before end of file. \n";
    }
    inFs.close();
    
}