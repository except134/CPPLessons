#pragma once

class Car
{
public:
    Car()
    {
        std::cout << "Car::Car()" << std::endl;
    }

    Car(const std::string& comp, const std::string& mod) :
        company(comp),
        model(mod)
    {
        std::cout << "Car::Car(" << company << ", " << model << ")" << std::endl;
    }

protected:
    std::string company{};
    std::string model{};
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar()
    {
        std::cout << "PassangerCar::PassangerCar()" << std::endl;
    }
};

class BusCar : virtual public Car
{
public:
    BusCar()
    {
        std::cout << "BusCar::BusCar()" << std::endl;
    }
};

class Minivan : public PassengerCar, public BusCar
{
public:
    Minivan()
    {
        std::cout << "Minivan::Minivan()" << std::endl;
    }

    Minivan(const std::string& comp, const std::string& mod) : Car(comp, mod)
    {
        std::cout << "Minivan::Minivan(" << company << ", " << model << ")" << std::endl;
    }
};

