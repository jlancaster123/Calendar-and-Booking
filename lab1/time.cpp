//time.cpp to implement your class
#include "time.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

TimeRange::TimeRange() // constuctor sets all ints to a impossible date
{
    int beginHour = -1;
    int beginMinute = -1;
    int endHour = -1;
    int endMinute = -1;
}

// get functions
int TimeRange::getBeginHour()
{
    return beginHour;
}

int TimeRange::getBeginMinute()
{
    return beginMinute;
}

int TimeRange::getEndHour()
{
    return endHour;
}

int TimeRange::getEndMinute()
{
    return endMinute;
}

bool TimeRange::isValid()
{
    if (beginHour < 24 && beginHour >= 0 && endHour < 24 && endHour >= 0 && (beginMinute == 30 | beginMinute == 0) && (endMinute == 30 | endMinute == 0)) // checks to see if hours are within 24 hour clock values and checks to see if minutes are 30 or 0
    {
        if ((beginMinute < endMinute && beginHour <= endHour) || (beginHour < endHour)) // makes sure that endhour is > beginhour if minute <= endminute
        {
            cout << "The time range is valid." << endl;
            return true;
        }
        else
        {
            cout << "The time range is invalid." << endl;
            return false;
        }
    }
    else
    {
        cout << "The time range is invalid." << endl;
        return false;
    }
}

void TimeRange::setTimeRange(int newBeginHour, int newbeginMinute, int newEndHour, int newEndMinute) // sets time range
{
    beginHour = newBeginHour;
    beginMinute = newbeginMinute;
    endHour = newEndHour;
    endMinute = newEndMinute;
}

void TimeRange::output()
{
    
    cout << "The time range is: " << setw(2) << setfill('0') << beginHour << ":" << setw(2) << setfill('0') << beginMinute << "-" << setw(2) << setfill('0') << endHour << ":" << setw(2) << setfill('0') << endMinute << endl;
    cout << "beginHour: " << setw(2) << setfill('0') << beginHour << endl << "beginMinute: "<< setw(2) << setfill('0') << beginMinute << endl << "endHour: " << setw(2) << setfill('0') << endHour << endl << "endMinute: " << setw(2) << setfill('0') << endMinute << endl;
    //printing and formatting the output
}