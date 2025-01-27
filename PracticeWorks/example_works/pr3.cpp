#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype> 
using namespace std;

class Date {
private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

public:
   Date(); 
   Date(unsigned m, unsigned d, unsigned y); 
   Date(const string &mn, unsigned d, unsigned y); 
   void printNumeric() const;
   void printAlpha() const;
private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   int number(const string &mn) const;
};


  Date::Date(){
    monthName = "January";
    month = 1;
    day = 1;
    year = 2000;
  } 

Date::Date(unsigned m, unsigned d, unsigned y) {
   bool isInvalidDate = false;
   unsigned correctDays; 
        if (m < 1) {
            month = 1;
             isInvalidDate = true;
        } else if (m > 12) {
            month = 12;
            isInvalidDate = true;
        }
         if (m <= 12 && m >= 1) {
            month = m;
         }
    monthName = name(month);
   
    correctDays = daysPerMonth(m, y);
    if (d <= correctDays && d >= 1) {
        day = d;  
    } else {
        unsigned maxDays =  daysPerMonth(m, y);
        isInvalidDate = true;
        if (d <= 0) {
            day = 1;
        } else if (d > maxDays) {
            day = maxDays;
        }
    }
   
    year = y;
   
    if (isInvalidDate == true) {
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "."<< endl;
    }
}
      
    Date::Date(const string &mn, unsigned d, unsigned y){
        string x = mn;
        monthName =x;
        bool isInvalidDate = false;
        bool isInvalidMonth =false;
        // x equals lowercase month
    if(x == "january" || x == "January"){
    month = 1;
   }
  else if(x == "february" || x == "February"){
    month = 2;
  }
  else if(x == "march"|| x == "March"){
    month = 3;
  }
  else if(x == "april" || x == "April"){
    month = 4;
  }
  else if(x == "may" || x == "May"){
   month = 5;
  }
  else if(x == "june" || x == "June"){
    month = 6;
  }
  else if(x == "july" || x == "July"){
    month =  7;
  }
  else if(x == "august" || x == "August"){
    month = 8;
  }
  else if(x == "september" || x == "September"){
    month = 9;
  }
  else if(x == "october" || x == "October"){
   month = 10;
  }
  else if(x == "november" || x == "November"){
    month = 11;
  }
  else if(x == "december"|| x == "December"){
    month = 12;
  }
  else{
    isInvalidMonth = true;
    month = 1;
    day=1;
    year= 2000;

  }
  
   unsigned correctDays; 
        if (month < 1) {
            month = 1;
             isInvalidDate = true;
        } else if (month > 12) {
            month = 12;
            isInvalidDate = true;
        }
         if (month <= 12 && month >= 1) {
            this->month = month;
         }
    monthName = name(month);
   
    correctDays = daysPerMonth(month, y);
    if (d <= correctDays && d >= 1) {
        day = d;  
    } else {
        unsigned maxDays =  daysPerMonth(month, y);
        isInvalidDate = true;
        if (d <= 0) {
            day = 1;
        } else if (d > maxDays) {
            day = maxDays;
        }
    }
   
    year = y;
   if(isInvalidMonth ==true){
      cout << "Invalid month name: the Date was set to 1/1/2000."<<endl;
      month = 1;
      day=1;
      year= 2000;
      isInvalidDate = false;
    }

    if (isInvalidDate == true) {
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "."<< endl;
    }
    

    } // closes off 

    void Date::printNumeric() const{
      cout << month << "/" << day << "/" << year;
    }


  
      void Date::printAlpha() const {
        cout << name(month) << " " << day << ", " << year;
      }


    bool Date::isLeap(unsigned y) const{
      bool leapYear = false;

      if(y % 4 ==0){
        leapYear = true;
      }
      if(y % 100 == 0){
            leapYear = false;
        }
         if (y % 400 == 0) {
            leapYear = true;
         }
      return leapYear;
   }

      unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
            if (m == 2) {
        // Check for leap year
          if (isLeap(y)) {
            return 29;
          } else {
            return 28;
        }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
          return 30;
          } else {
         return 31;
      }
  }

  string Date::name(unsigned m) const{
      if (m <= 1){
        return "January";
      }
      else if (m == 2){
        return "February";
      }
      else if (m == 3){
        return "March";
      }
      else if (m == 4){
        return "April";
      }
      else if (m == 5){
        return "May";
      }
      else if (m == 6){
        return "June";
      }
      else if (m == 7){
        return "July";
      }
      else if (m == 8){
        return "August";
      }
      else if (m == 9){
        return "September";
      }
      else if (m == 10){
        return "October";
      }
      else if (m == 11){
        return "November";
      }
      else if (m >= 12){
        return "December";
      }
        else{
          return "ERROR";
        }
    }
  
  // closes 
    int Date::number(const string &mn) const {
      if (mn == "January" || mn == "january"){
      return 1;
    } 
      else if (mn == "February" || mn == "february"){
        return 2;
      }
      else if (mn == "March" || mn == "march"){
        return 3;
      } 
      else if (mn == "April" || mn == "april"){
        return 4;
      } 
      else if (mn == "May" || mn == "may"){
        return 5;
      } 
      else if (mn == "June" || mn == "june"){
        return 6;
      } 
      else if (mn == "July" || mn == "july"){
        return 7;
      }
      else if (mn == "August" || mn == "august"){
        return 8;
      }
      else if (mn == "September" || mn == "september"){
        return 9;
      }
      else if (mn == "October" || mn == "october") {
        return 10;
      }
      else if (mn == "November" || mn == "november"){
        return 11;
      }
      else if (mn == "December" || mn == "december"){
        return 12;
      }
    return 0; // Invalid month
    } //closes int numb

 // closes class




// Implement the Date member functions here


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
