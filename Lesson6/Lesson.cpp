#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    auto number = GetUserInput<int>("Введите одно целое число");
    std::cout << "Введенно число " << number << endll;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    std::cout << "Проверка 1" << endll;
    std::cout << "Проверка 2" << endll;
    std::cout << "Проверка конец" << endll;

    Player p("VVV");
    p.Add(new Card{CardFace::Eight, CardSuit::Diamond});
    p.Add(new Card{CardFace::Two, CardSuit::Club});
    p.Add(new Card{CardFace::Ace, CardSuit::Spade});
    p.Open();
    std::cout << p;

    p.IsHitting();
}

