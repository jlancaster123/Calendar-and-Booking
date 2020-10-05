//date.cpp to implement your class
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#include "date.hpp"
//constructer for the date not used atm but works
// Date::Date(int newDay, int newMonth)
// {
//     setDate(newDay,newMonth);
//     for(int i=0;i<48;i++)
//     {
//         appointed[i]=false;
//     }

// }

Date::Date() // constructor
{
    month = 0;
    day = 0;
    for (int i = 0; i < 48; i++)
    {
        appointed[i] = false;
    }
}

int Date::setDate(int newDay, int newMonth)
{

    day = newDay;
    month = newMonth;
    //isValid();
    //isHoliday();
    //isWeekend();

    return 0;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

void Date::getAppointed()
{
    cout << "Appointed array:";

    for (int i = 0; i < 48; i++)
    {
        cout << appointed[i];
    }
    cout << endl;
}

void Date::output()
{
    cout << "The date is (dd/mm):  " << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << endl;
   // printFreeTimeSlots();
    //printAppointedTimeSlots();
    getAppointed();

    //totallyValid();
}

bool Date::isValid() // checks to see if the date is within the values we are given[]
{
    bool tempDay = true, tempMonth = true;

    if (month < 9 || month > 12)
    {
        tempMonth = false;
    }
    else if (month == 9)
    {
        if (day > 30 || day < 8)
        {
            tempDay = false;
        }
    }
    else if (month == 10)
    {
        if (day > 31 || day < 1)
        {
            tempDay = false;
        }
    }
    else if (month == 11)
    {
        if (day > 30 || day < 1)
        {
            tempDay = false;
        }
    }
    else if (month == 12)
    {
        if (day > 20 || day < 1)
        {
            tempDay = false;
        }
    }

    if (tempDay == false || tempMonth == false)
    {
        cout << "Error:  Date must be between September 8 to December 20." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isHoliday()
{
    const int holidayDays[] = {12, 11};
    const int holidayMonths[] = {10, 11};

    for (int i = 0; i < sizeof(holidayDays) + 1; i++)
    {
        if (day == holidayDays[i] & month == holidayMonths[i])
        {
            cout << "The date is a holiday." << endl;
            return true;
        }
    }
    // cout << "It is not a holiday" << endl;
    return false;
}

bool Date::isWeekend()
{
    //Zellers algorithm  used to find out the day of the week

    int tempMonth;
    int firstTwoDigits = 2020 % 100;
    int lastTwoDigits = 2020 / 100;
    int total;
    if (month > 2)
    {
        tempMonth = month;
    }
    else
    {
        tempMonth = (12 + month);
    }
    total = day + floor((13 * (tempMonth + 1) / 5) + firstTwoDigits + floor(firstTwoDigits / 4) + floor(lastTwoDigits / 4) + (5 * lastTwoDigits));
    total = total % 7;
    if (total == 0 | total == 1)
    {
        cout << "You are not allowed to book on a weekend." << endl;
        return true;
    }
    else
    {
       // cout << "That date is not a weekend." << endl;
        return false;
    }
}

void Date::printFreeTimeSlots() // uses a function because its the same as appointed time slots just printing at different times
{

    cout << "The times available are: ";
    timeSlots(0);
}

void Date::printAppointedTimeSlots()
{

    cout << "The times unavailable are: ";
    timeSlots(1);
}

void Date::timeSlots(int temp)
{
    //temp is 0 for free time slots and 1 for appointed
    for (int i = 0; i < 48 + 1; i++)
    {
        if ((appointed[i] == false & temp == 0) || (appointed[i] == true & temp == 1))
        //prints if unappointed and free time mode
        // or if appointed and on printAppointedTimeSlots
        {
            int hour = i / 2;
            int minute = i % 2;
            cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute * 30;
            if (i < 49)
            {
                cout << ", ";
            }
        }
    }
    cout << endl;
}

bool Date::totallyValid() // does all the checks at once
{
    if (isValid() && !isHoliday() && !isWeekend())
    {

        return true;
    }
    else
    {
        return false;
    }
}

bool equal(Date testDay, Date testDay2)
{
    if (testDay.day == testDay2.day && testDay.month == testDay2.month)
    {
        cout << "The dates are equal." << endl;
        return true;
    }
    else
    {
        cout << "The dates are unequal." << endl;
        return false;
    }
}
