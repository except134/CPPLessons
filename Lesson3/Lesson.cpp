#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    Parallelogram parallelogram(10,20);
    parallelogram.Print();

    Circle circle(10);
    circle.Print();

    Rectangle rectangle(10,20);
    rectangle.Print();

    Square square(10);
    square.Print();

    Rhombus rhombus(10);
    rhombus.Print();

    std::cout << std::endl;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    /* ВЫВОД
    Car::Car()
    PassangerCar::PassangerCar()
    BusCar::BusCar()
    Minivan::Minivan()
    */
    Minivan minivan;

    std::cout << std::endl;

    /* ВЫВОД
    Car::Car(Суперфирма, Суперминивен)
    PassangerCar::PassangerCar()
    BusCar::BusCar()
    Minivan::Minivan(Суперфирма, Суперминивен)
     */
    Minivan minivan2("Суперфирма", "Суперминивен");

    std::cout << std::endl;
}

void Lesson::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;


    std::cout << std::endl;
}

