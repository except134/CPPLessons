#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "Проверка на високосный год" << std::endl;
    std::cout << "--------------------------" << std::endl;

    Date dleap0(31,11,2020);

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
}

void Lesson::Task2()

{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

}

void Lesson::BlackjackTest()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Blackjack test" << std::endl;
    std::cout << "=========================" << std::endl;

}
