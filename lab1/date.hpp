//header file date.hpp to declare your class
#include <iostream>

using namespace std;
class Date {
  public:
    //Date (int newDay,int newMonth);
    Date ();
    int getDay();//returns day value
    int getMonth(); // returns month value
    void getAppointed(); // gives appointed times
    int setDate(int newDay, int newMonth); // takes day and month and saves their values
    void printFreeTimeSlots (); // prints free time slots
    void printAppointedTimeSlots(); // prints appointed time slots
    void output(); /// outputs the month date and appointed array
    friend bool equal(Date testDay, Date testday2); // takes two classes of type date  and equates the two classes by their day and month
    bool totallyValid(); // checks to see if it is a weekday holiday and valid date




  private: 
    int month; // month
    int day; // day
    bool appointed [48]; // array corresponding to the half hour valid time intervals
    bool isValid (); // checks if the date is valid
    bool isHoliday(); // checks if the date is a holiday
    bool isWeekend(); // checks if the date is a weekend
    void timeSlots(int temp); // prints out available slots if given 0 unavailable for 1

    



};
