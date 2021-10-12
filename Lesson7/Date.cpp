#include "Lesson.h"
#include "Date.h"

bool Date::CheckForFebruaryAndNotLeapYear() const
{
    return( static_cast<unsigned int>(month) == MonthNames::February &&
            !year.IsLeap() &&
            static_cast<unsigned int>(day) == DaysInMonth[MonthNames::February]);
}

Date& Date::operator++()
{
    ++day;

    if(static_cast<unsigned int>(day) > (year.IsLeap() ? DaysInMonth[static_cast<unsigned int>(month)] : DaysInMonth[static_cast<unsigned int>(month)] - 1)) {
        day = Day::Minimal();
        ++month;
        if(static_cast<unsigned int>(month) > Month::Maximal()) {
            month = Month::Minimal();
            ++year;
        }
    }

    if(CheckForFebruaryAndNotLeapYear())
        --day;

    return *this;
}

Date Date::operator++(int)
{
    auto temp(*this);

    ++(*this);

    return temp;
}

Date& Date::operator--()
{
    --day;
    if(static_cast<unsigned int>(day) < Day::Minimal()) {
        day = DaysInMonth[static_cast<unsigned int>(month) - 1];
        --month;
        if(static_cast<unsigned int>(month) < Month::Minimal()) {
            month = Month::Maximal();
            --year;
        }
        if(CheckForFebruaryAndNotLeapYear())
            --day;
    }

    return *this;
}

Date Date::operator--(int)
{
    auto temp(*this);

    --(*this);

    return temp;
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
    if(!date.IsValid()) {
        stream << "Дата (плохой формат даты): " << date.day << "." << date.month << "." << date.year;
    }
    else
        stream << date.day << "." << date.month << "." << date.year;
    return stream;
}

