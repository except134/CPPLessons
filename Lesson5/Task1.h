#pragma once

template<typename T>
class Pair1
{
public:
    Pair1(const T& p1, const T& p2) :
        param1(p1),
        param2(p2)
    {}

    void SetParam1(const T& p) { param1 = p; }
    void SetParam2(const T& p) { param2 = p; }

    T First() const { return param1; }
    T Second() const { return param2; }

private:
    T param1{};
    T param2{};
};
