//Default constructor that will automatically set up feet and inches to 0 if nothing is put in
#include "Distance.h"
#include <cmath>
Distance::Distance() {
     _feet = 0;
     _inches = 0.0;
}
//This will get the user inputted feet and inches and set them 
Distance::Distance(unsigned ft, double in) { //In progress 
     _feet = ft;
     _inches = in;
          
     init();             //Calls the init() function which is used to check if 
                         //any inches are negative or go over 12
}
//Will set feet to 0 if nothing is put in feet but will put something for inches
Distance::Distance(double in) {
     _feet = 0;
     _inches = in;

     init();             
}
//Will get/give feet whenever called
unsigned Distance::getFeet() const {
     return _feet;
}

//Will get/give inches whenever called
double Distance::getInches() const {
     return _inches;
}

//Convers feet into inches (multiply by 12) and adds them to get the total amount of inches
double Distance::distanceInInches() const {
     return _inches + (_feet * 12);
}

//Gets the amount of inches and addes it into feet (example 8' 6" will turn into 8.5 feet)
double Distance::distanceInFeet() const {
     return _feet + (_inches / 12.0);
}

//Converts inches into meters
double Distance::distanceInMeters() const {
     return (_inches + (_feet * 12)) * 0.0254;
}

//Returns the sum
Distance Distance::operator+(const Distance &rhs) const {
     Distance sumDistance;
     
     sumDistance._feet = _feet + rhs._feet;
     sumDistance._inches = _inches + rhs._inches;
     sumDistance.init();
     return sumDistance;
}


//Returns the difference
Distance Distance::operator-(const Distance &rhs) const {

double diff = 0;

diff = this->distanceInInches() - rhs.distanceInInches();
Distance converted(diff);

return converted;

}

//This will override the << operator which will make it so that it does that same action (<< in this case) multiple times under one call to get the output we desire of feet and inches
ostream & operator<<(ostream &out, const Distance &rhs) {        //You only have to delete "friend" to get the function to work
     out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
     return out;
   }

   /* Constructs a distance of 0 ft and in inches.
        Calls the init() helper function to convert negative inches to positive
        and any excess inches to feet.
   */

  //This is used to check if inches is negative and will turn it into positive number or if inches are over 12, it will round up and add towards feet
void Distance::init() {         //You have to add Distance so that it knows that its part of the Distance class
     if (_inches < 0) {                 //Conversts inches to positive if its
          _inches *= -1;                //given as a negative
     }

     if (_inches >= 12) {
          _feet += _inches / 12;
          _inches = fmod(_inches, 12);                   
     }
   } 