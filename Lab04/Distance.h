//Distance.h: 
//the Distance class header (aka interface) file
//Contains the declaration of the Distance class

#ifndef DISTANCE_H       // (if not defined = ifndef) (safety procaution)
#define DISTANCE_H       // Define distance_H

#include <iostream>
using namespace std;

class Distance {
 public:                 // any methods and members within are accessible from outside the class
    Distance();
    Distance(unsigned ft, double in); // Constructor with 2 values feet,inches as arguments paramaterized
    explicit Distance(double in);     // Constructor with 1 value takes only inches (explicit to prevent implicit conversions)

    unsigned getFeet() const;        // Gets feet and returns an unsigned integer
    double getInches() const;        // Gets inches and returns a double

    double distanceInInches() const; // distance to inches
    double distanceInFeet() const;   // distance to feet
    double distanceInMeters() const; // distance to meters

// shows how the class cause use this operator with distance objects //operator allows me to + or - distances
    Distance operator+(const Distance &rhs) const; // Overloads the + operator sum two Distance
    Distance operator-(const Distance &rhs) const; // Overload the - operator difference two Distance

            // operator<< allows me to output distance value in feet and inches
    friend ostream &operator<<(ostream &out, const Distance &rhs); // Friend function to overload << for output

 private:                // Private section - variables and methods only accessible within the class
    unsigned _feet;      // Private variable to store feet (unsigned int)
    double _inches;      // Private variable to store inches (double)

    void init();         // initializes/normalizes the feet and inches
};

#endif            // ends the conditional block that I started with #ifndef


//friend (allows the function to access private members like _feet and _inches )
// rhs (right hand side)
//ostream &out (passby reference)

