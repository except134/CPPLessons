#pragma once

template<typename T1, typename T2>
class Pair
{
public:
    Pair(T1 p1, T2 p2) :
            param1(p1),
            param2(p2)
    {}

    void SetParam1(T1 p) { param1 = p; }
    void SetParam2(T2 p) { param2 = p; }

    T1 First() const { return param1; }
    T2 Second() const { return param2; }

private:
    T1 param1{};
    T2 param2{};
};
