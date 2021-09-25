#pragma once

class Power
{
public:
    Power() : number1(10), number2(2) {}
    Power(double n1, double n2) : number1(n1), number2(n2) {}

    void Set(double n1, double n2)  { number1 = n1; number2 = n2; }
    double Calculate() { return pow(number1, number2); }

private:
    double number1{0};
    double number2{0};
};

