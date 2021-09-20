#pragma once

class Fruit
{
public:
    Fruit() = default;
    Fruit(const std::string& n, const std::string& c) :
        name(n),
        color(c)
    {}

    const std::string GetName() const { return name; }
    const std::string GetColor() const { return color; }

private:
    std::string name{};
    std::string color{};
};

class Apple : public Fruit
{
public:
    Apple(const std::string& c) :
        Fruit("яблоко", c)
    {}
};

class Banana : public Fruit
{
public:
    Banana() :
        Fruit("банан", "желтый")
    {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith() :
        Apple("зеленое")
    {}
};

class FruitsProcess
{
public:
    void Run()
    {
        Apple a("красное");
        Banana b;
        GrannySmith c;

        std::cout << "Мое " << a.GetName() << " " << a.GetColor() << ".\n";
        std::cout << "Мой " << b.GetName() << " " << b.GetColor() << ".\n";
        std::cout << "Мое " << c.GetName() << " " << c.GetColor() << ".\n";
    }
};

