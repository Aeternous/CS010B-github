#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Car {
   string type;
   int year;
};

int main() {
   vector<Car> carList(3);
   int i;
   Car chosenCar;

   for (i = 0; i < carList.size(); ++i) {
      cin >> carList.at(i).type;
      cin >> carList.at(i).year;
   }

   chosenCar = carList.at(0);
   for (i = 0; i < carList.size(); ++i) {
      if (carList.at(i).year > chosenCar.year) {
          chosenCar = carList.at(i);
      }
   }

   cout << "Result: " << chosenCar.year << endl;

   return 0;
}