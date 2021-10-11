#pragma once

// TODO: Сделать учет количества дней в месяце, сейчас всегда считается, что 31, сделать учет високосного года
class Date
{
public:
    Date() = default;
    Date(const Date&) = default;
    Date& operator=(const Date&) = default;
    Date(unsigned int d, unsigned int m, unsigned int y);

    void Set();
    void SetDay(unsigned int d);
    void SetMonth(unsigned int m);
    void SetYear(unsigned int y);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    friend std::ostream& operator<<(std::ostream& stream, const Date& date);
    friend std::istream& operator>>(std::istream& stream, Date& date);

private:
    bool IsValidDay() const;
    bool IsValidMonth() const;
    bool IsValidYear() const;
    bool IsLeapYear() const;

private:
    unsigned int day{1};
    unsigned int month{1};
    unsigned int year{1970};
};

inline std::ostream& operator<<(std::ostream& stream, const Date& date)
{
    std::cout.fill('0');
    stream << "Дата: " << std::setw(2) << date.day << "." << std::setw(2) << date.month << "." << std::setw(4) << date.year << std::endl;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, Date& date)
{
    stream >> date.day;
    stream >> date.month;
    stream >> date.year;

    return stream;
}


