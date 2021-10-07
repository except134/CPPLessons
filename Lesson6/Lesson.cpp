#include "Lesson.h"

template<typename T>
Foo<T>::Foo()
{
    // ...
}
template<typename T>
void Foo<T>::someMethod(T x)
{
    // ...
}

void Lesson::Task1()
{
    Foo<int> f;
    f.someMethod(5);
    
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
}

void Lesson::BlackjackTest()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Blackjack test" << std::endl;
    std::cout << "=========================" << std::endl;

    Player p("VVV");
    p.Add(new Card{CardFace::Eight, CardSuit::Diamond});
    p.Add(new Card{CardFace::Two, CardSuit::Club});
    p.Add(new Card{CardFace::Ace, CardSuit::Spade});
    p.Open();
    std::cout << p;

    p.IsHitting();
}
