//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Jake Lancaster / Dante Umpherville-Choy / Albert Beauchamp
// 301377815      / 301381822              / 301411857
//
// Group 45
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
// This code asks a user for a date and time and puts the information into a class
// then it prints out the class info for the date and time range
// next it asks the user for input to overwrite the data
// prints out new information
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
//#include "time.hpp"
#include "date.hpp"
#include "time.hpp"
using namespace std;
void bookingInterface(Date &day, TimeRange &timePeriod);   // function that asks the user for date and time input
void dateAndRangeOutput(Date &day, TimeRange &timePeriod); // prints the information of a date and time range

int main()
{
  char exit = 'a';
  while (exit != 'n' && exit != 'N')
  {

    // Defining a date and a time range class
    Date testDay;
    Date testDay2;
    TimeRange tempDay1;

    // asking for input then printing it
    cout << "Hello welcome to the program. " << endl;
    bookingInterface(testDay, tempDay1);
    dateAndRangeOutput(testDay, tempDay1);

    // asking for new input and printing it
    cout << "Would you like to set another date and time?" << endl;
    bookingInterface(testDay, tempDay1);
    dateAndRangeOutput(testDay, tempDay1);

    cout << "Would you like to run again? y or n?" << endl;
    cin >> exit;
  }
  return 0;
}

void bookingInterface(Date &day, TimeRange &timePeriod)
{
  // defining temporary variables
  bool wrongDate = true;
  bool wrongTime = true;
  int tempDay;
  int tempMonth;
  int tempHour;
  int tempMinutes;
  int tempEndHour;
  int tempEndMinutes;

  // allows the user to keep inputting until they get a valid date
  // and takes the valid information and stores it
  while (wrongDate)
  {

    cout << "What month would you like to book your appointment?" << endl;
    cin >> tempMonth;
    cout << "What day would you like to book your appointment?" << endl;
    cin >> tempDay;
    day.setDate(tempDay, tempMonth);

    wrongDate = (!day.totallyValid());

    if (wrongDate)
    {
      cout << "Error:  Invalid date.  Please try again." << endl;
    }
    //clears inputs when invalid cases such as letters
    cin.clear();
    cin.ignore(1000, '\n');
  }
  while (wrongTime)
  {
    cout << endl;
    cout << "What hour would you like to start? ";
    cin >> tempHour;
    cout << "What minute would you like to start? ";
    cin >> tempMinutes;
    cout << "What hour would you like to end? ";
    cin >> tempEndHour;
    cout << "What minute would you like to end? ";
    cin >> tempEndMinutes;

    timePeriod.setTimeRange(tempHour, tempMinutes, tempEndHour, tempEndMinutes);

    wrongTime = (!timePeriod.isValid());
    if (wrongTime)
    {
      cout << "Error:  Invalid time.  Please try again." << endl;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }
}

//outputs date and range
void dateAndRangeOutput(Date &day, TimeRange &timePeriod)
{
  cout << "----------------------------" << endl;
  day.output();
  cout << "----------------------------" << endl;
  timePeriod.output();
  cout << "----------------------------" << endl;
}


//Code testing out equals function.

// cout << "Second day?" << endl;
// cin >> tempDay;
// cout << "Second month?" << endl;
// cin >> tempMonth;
// testDay2.setDate(tempDay, tempMonth);
// testDay2.output();
// cout << "----------------------------" << endl;
// cout << "----------------------------" << endl;
// equal(testDay, testDay2);
// cout << "----------------------------" << endl;
