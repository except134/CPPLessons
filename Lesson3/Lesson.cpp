#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    Parallelogram parallelogram(10,20);
    Circle circle(10);
    Rectangle rectangle(10,20);
    Square square(10);
    Rhombus rhombus(10);

    auto Print = [](Figure* f) {f->Print();};

    Print(&parallelogram);
    Print(&circle);
    Print(&rectangle);
    Print(&square);
    Print(&rhombus);

    std::cout << std::endl;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    /* ВЫВОД
     * Car::Car()
     * PassangerCar::PassangerCar()
     * BusCar::BusCar()
     * Minivan::Minivan()
     */
    Minivan minivan;

    std::cout << std::endl;

    /* ВЫВОД
     * Car::Car(Суперфирма, Суперминивен)
     * PassangerCar::PassangerCar()
     * BusCar::BusCar()
     * Minivan::Minivan(Суперфирма, Суперминивен)
     */
    Minivan minivan2("Суперфирма", "Суперминивен");

    std::cout << std::endl;
}

void Lesson::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;

    Fraction f1(100, 22);
    Fraction f2(34, 23);

    if(f1 > f2) {
        std::cout << f1 << " больше " << f2 << std::endl;
    } else {
        std::cout << f1 << " меньше " << f2 << std::endl;
    }

    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;

    std::cout << f1 << " * 5 = " << f1 * int64_t(5) << std::endl;
    f1.Print();
    std::cout << std::endl;

    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;

    Fraction f3(100, 22);
    Fraction f4(100, 22);

    if(f3 == f4) {
        std::cout << f3 << " равно " << f4 << std::endl;
    } else {
        std::cout << f3 << " не равно " << f4 << std::endl;
    }

    f3++;

    if(f3 == f4) {
        std::cout << f3 << " равно " << f4 << std::endl;
    } else {
        std::cout << f3 << " не равно " << f4 << std::endl;
    }

    std::cout << std::endl;
}

void Lesson::Task4()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 4" << std::endl;
    std::cout << "=========================" << std::endl;

    Card c(CardFace::King, CardSuit::Heart);
    c.Show();
    c.Flip();
    c.Show();
}

