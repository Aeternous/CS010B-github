#include <iostream>
#include "IntVector.h"

using namespace std;

int main(){

    IntVector vect1(5, 3);
    cout << "Size: " << vect1.size() << "\n"; // expected 5
    cout << "Capacity: " << vect1.capacity() << "\n"; // Expected 5
    cout << "Empty: " << vect1.empty() << "\n"; //expected 0

    //testing front and back functions
    cout << "Front: " << vect1.front() << "\n"; // expected 3
    cout << "Back: " << vect1.back() << "\n"; 
    
    //testing at function
    try{
        cout << "At index 2: " << vect1.at(2) << "\n";
        cout << "At index 5: " << vect1.at(5) << "\n";
    } catch (const out_of_range &e) {
        cerr << e.what() << "\n"; 
    }
    return 0;
}