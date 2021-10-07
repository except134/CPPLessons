#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.First() << ' ' << p1.Second() << std::endl;

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.First() << ' ' << p2.Second() << std::endl;

    std::cout << std::endl;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.First() << ' ' << p1.Second() << std::endl;

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.First() << ' ' << p2.Second() << std::endl;

    std::cout << std::endl;
}

void Lesson::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.First() << ' ' << svp.Second() << std::endl;

    std::cout << std::endl;
}

void Lesson::Task4()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 4" << std::endl;
    std::cout << "=========================" << std::endl;


    std::cout << std::endl;
}

