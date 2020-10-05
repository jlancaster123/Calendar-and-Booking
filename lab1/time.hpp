//header file time.hpp to declare your class
#include <iostream>
class TimeRange 
{
    public:
    TimeRange(); // constructor
    int getBeginHour(); // get functions
    int getBeginMinute();
    int getEndHour();
    int getEndMinute();
    bool isValid(); // validates time
    void setTimeRange(int newBeginHour, int newbeginMinute, int newEndHour, int newEndMinute); // Takes the start and end time as int and sets the time range
    void output(); // outputs the time range

    private:

    int beginHour;
    int beginMinute;
    int endHour;
    int endMinute;
    
    
  
};
