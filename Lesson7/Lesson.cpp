#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "Проверка на високосный год" << std::endl;
    std::cout << "--------------------------" << std::endl;

    Date dleap1(1,3,2020);
    std::cout << "Начальная дата (год високосный): " << dleap1 << std::endl;
    std::cout << "Дата за минусом 1 день (год високосный): " << --dleap1 << std::endl;
    std::cout << "Прибавляем 1 день (год високосный): " << ++dleap1 << endll;

    Date dleap2(1,3,2021);
    std::cout << "Начальная дата (год не високосный): " << dleap2 << std::endl;
    std::cout << "Дата за минусом 1 день (год не високосный): " << --dleap2 << std::endl;
    std::cout << "Прибавляем 1 день (год не високосный): " << ++dleap2 << endll;

    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* now = std::localtime(&tt);

    SmartPtr<Date> today(new Date(now->tm_mday,now->tm_mon,now->tm_year + 1900));
    SmartPtr<Date> date;
    std::cout << "Текущая дата (today): " << *today << std::endl;
    std::cout << "today = " << (today.Get() != nullptr ? today.Get() : nullptr) << std::endl;
    std::cout << "date = " << (date.Get() != nullptr ? date.Get() : nullptr) << std::endl;

    date = today;
    std::cout << "Текущая дата (date): " << *date << std::endl;
    std::cout << "today = " << (today.Get() != nullptr ? today.Get() : nullptr) << std::endl;
    std::cout << "date = " << (date.Get() != nullptr ? date.Get() : nullptr) << std::endl;
}

const SmartPtr<Date>& CompareDatesNoEqual(const SmartPtr<Date>& d1, const SmartPtr<Date>& d2)
{
    return *d1 > *d2 ? d1 : d2;
}

void ExchangeDates(SmartPtr<Date>& d1, SmartPtr<Date>& d2)
{
    SmartPtr<Date> temp(d1);
    d1 = d2;
    d2 = temp;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    SmartPtr<Date> date1(new Date(10,4,2021));
    SmartPtr<Date> date2(new Date(5, 8, 2020));

    std::cout << "Дата 1: " << *date1 << std::endl;
    std::cout << "Дата 2: " << *date2 << std::endl;

    std::cout << "Сравниваем, возвращаем наибольшее: " << *CompareDatesNoEqual(date1, date2) << std::endl;
    std::cout << "Обмениваем даты." << std::endl;
    ExchangeDates(date1, date2);
    std::cout << "Дата 1: " << *date1 << std::endl;
    std::cout << "Дата 2: " << *date2 << std::endl;

}

void Lesson::BlackjackTest()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Blackjack test" << std::endl;
    std::cout << "=========================" << std::endl;

}
