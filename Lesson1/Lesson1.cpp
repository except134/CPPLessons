#include "Lesson1.h"

void Lesson1::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    Power pwr;
    Power pwrDef;

    std::cout << "(Значения по умолчанию N1=10, N2=2) N1 ^ N2 = " << pwrDef.Calculate() << std::endl << std::endl;

    double n1 = 0, n2 = 0;
    std::cout << "Введите число 1: ";
    std::cin >> n1;
    std::cout << "Введите число 2: ";
    std::cin >> n2;

    pwr.Set(n1, n2);

    std::cout << "N1 ^ N2 = " << pwr.Calculate() << std::endl;
    std::cout << std::endl;
}

uint8 Lesson1::GetUint8(const std::string& str)
{
    int in = 0;
    for(;;) {
        std::cout << str;
        std::cin >> in;
        if (in >= std::numeric_limits<uint8>::min() && in <= std::numeric_limits<uint8>::max()) {
            break;
        }
        std::cerr << "Ошибка: Неверное число для uint8" << std::endl;
    }

    return static_cast<uint8>(in);
}

void Lesson1::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    uint16 r = 0, g = 0, b = 0, a = 0;
    r = GetUint8("Введите значение для красного цвета: ");
    g = GetUint8("Введите значение для зеленого цвета: ");
    b = GetUint8("Введите значение для голубого цвета: ");
    a = GetUint8("Введите значение для альфа канала: ");

    RGBA rgba(r, g, b, a);
    rgba.Print();

    std::cout << std::endl;
}

void Lesson1::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;

    Stack stack;
    stack.Reset();
    stack.Print();

    stack.Push(3);
    stack.Push(7);
    stack.Push(5);
    stack.Print();

    stack.Pop();
    stack.Print();

    stack.Pop();
    stack.Pop();
    stack.Print();

    stack.Pop();
    stack.Print();

    for (int i = 1; i <= 16; ++i) {
        if(!stack.Push(i)) {
            std::cout << "Стэк полон." << std::endl;
            break;
        }
    }
    stack.Print();

    stack.Reset();

    std::cout << std::endl;
}

