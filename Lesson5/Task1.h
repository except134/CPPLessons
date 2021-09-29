#pragma once

template<typename T>
class Pair1
{
public:
    Pair1(T p1, T p2) :
        param1(p1),
        param2(p2)
    {}

    void SetParam1(T p) { param1 = p; }
    void SetParam2(T p) { param2 = p; }

    T First() const { return param1; }
    T Second() const { return param2; }

private:
    T param1{};
    T param2{};
};
