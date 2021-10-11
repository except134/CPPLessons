#include "Lesson.h"
#include "Date.h"

Date::Date(unsigned int d, unsigned int m, unsigned int y)
 {
    SetDay(d);
    SetMonth(m);
    SetYear(y);
}

bool Date::IsValidDay() const
{
    return (day > 0 && day <= 31);
}

bool Date::IsValidMonth() const
{
    return (month > 0 && month <= 12);
}

bool Date::IsValidYear() const
{
    return (year >= 1 && year <= 9999);
}

bool Date::IsLeapYear() const
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400);
}

Date& Date::operator++()
{
    day++;
    if(day == 32) {
        day = 1;
        month++;
        if(month == 13) {
            month = 1;
            year++;
        }
    }

    return *this;
}

Date Date::operator++(int)
{
    Date temp(day, month, year);

    ++(*this);

    return temp;
}

Date& Date::operator--()
{
    day--;
    if(day == 0) {
        day = 31;
        month--;
        if(month == 0) {
            month = 12;
            year--;
        }
    }

    return *this;
}

Date Date::operator--(int)
{
    Date temp(day, month, year);

    --(*this);

    return temp;
}

void Date::SetDay(unsigned int d)
{
    day = d;
}

void Date::SetMonth(unsigned int m)
{
    month = m;
}

void Date::SetYear(unsigned int y)
{
    year = y;
}
