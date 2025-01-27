#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;


void readData(const string & fileName, vector<double> & flightDeg, vector<double> & liftDeg);
double interpolation(double num, const vector<double> & flightDeg, const vector<double> & liftDeg);
bool isOrdered(const vector<double> & flightDeg);
void reorder(vector<double> & flightDeg, vector<double> & liftDeg);



int main(int argc, char* argv[]){
    if (argc < 2) {
        cout << "Error: No file provided." << endl;
        return 1;
    }

    double num1;
    string file;
    vector<double> flightDeg;
    vector<double> liftDeg;

    file = argv[1];  // Use the file name passed as a command-line argument

    readData(file, flightDeg, liftDeg);

    // First, check if the data is ordered and reorder if necessary
    //Using rubberducking here to capture an issue
    if (!isOrdered(flightDeg)) {
        reorder(flightDeg, liftDeg);
    }

    cin >> num1;

    if (num1 < flightDeg.front() || num1 > flightDeg.back()) {
        cout << "Input angle is out of bounds." << endl;
        return 1;  // Exit if the input is out of range
    }

    string input;

    while(1){
        cin >> num1;
        double result = interpolation(num1, flightDeg, liftDeg);
        cout << result << endl;

        bool loop = true;

        while(loop){
            cin >> input;
            
            if (input == "No"){
                loop = false;
            }
        }
    }
    

    return 0;
}

void readData(const string & fileName, vector<double> & flightDeg, vector<double> & liftDeg){
    double angle = 0.0; 
    double liftCoeff = 0.0;
    ifstream inFS;
    inFS.open(fileName);

    if (!inFS.is_open()){
      cout << "Error opening " << fileName << endl;
      exit(EXIT_FAILURE);
    }
    
    while(inFS >> angle >> liftCoeff){
        flightDeg.push_back(angle);
        liftDeg.push_back(liftCoeff);
    }

    inFS.close();

}

double interpolation(double num, const vector<double> & flightDeg, const vector<double> & liftDeg){
    /*if(num < flightDeg.front() || num > flightDeg.back()){
        cout << "Input angle is out of bounds." << endl;
        exit(EXIT_FAILURE);
    }*/
    //Go upto second-last element to prevent out of bounds error
    for (unsigned int i = 0; i < flightDeg.size() - 1; ++i){
        if (num >= flightDeg.at(i) && num <= flightDeg.at(i + 1)){
            double angleA = flightDeg.at(i);
            double angleC = flightDeg.at(i + 1);
            double liftA = liftDeg.at(i);
            double liftC = liftDeg.at(i + 1);

            double liftB = liftA + ((num - angleA)/(angleC - angleA)) * (liftC - liftA);
            return liftB;
        }
    }
    exit(EXIT_FAILURE);
}


bool isOrdered(const vector<double> & flightDeg){
    if(flightDeg.size() <= 1){
        return true;
        //Checks for empty or single element vectors and can keep them ordered as true with no specific order mechanic
        //Prevents Segmentation fault(-11)
    }
    for(unsigned int i = 0; i < flightDeg.size() - 1; ++i){
        if(flightDeg.at(i) > flightDeg.at(i + 1)){
            return false;
        }
    }
    return true;
}

void reorder(vector<double> & flightDeg, vector<double> & liftDeg){
    if(flightDeg.empty() || liftDeg.empty()){
        return;
        //if the two vectors are empty, then there is nothing to reorder
        //Prevents Segmentation fault(-11)
    }
    if(flightDeg.size() != liftDeg.size()){
        exit(EXIT_FAILURE);
        //Ensures that both vector sizes are same, so we can use one for loop to compare the order
    }
    for (unsigned int i = 0; i < flightDeg.size() - 1; ++i){
        unsigned int minIndex = i;

        for (unsigned int j = i + 1; j < flightDeg.size(); ++j){
            if(flightDeg.at(j) < flightDeg.at(minIndex)){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(flightDeg.at(i), flightDeg.at(minIndex));
            swap(liftDeg.at(i), liftDeg.at(minIndex)); 
            //Since both vector sizes are the same, and work in parallel, we can ensure alignment
        }
    }
}

//Temp code that was originally written within void reorder:
/*double tempVal;
tempVal = flightDeg[i];
flightDeg[i] = flightDeg[i + 1];
flightDeg[i + 1] = tempVal;*/

/*double tempVal;
tempVal = liftDeg[i];
liftDeg[i] = liftDeg[i + 1];
liftDeg[i + 1] = tempVal;*/