#include <iostream>
using namespace std;

int main(){
    double miles, kilometers;
    

    cout << "How many miles did you walk today? \n";
    cin >> miles;

    kilometers = 1.6*miles;
    
    cout << "You have walked " << kilometers << " kilometers today!";

    return 0;
}