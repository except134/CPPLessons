#pragma once

#include "Hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer() : Hand() {}

    virtual bool IsHitting() = 0;

    bool IsBoosted() { return false; }
    void Bust() { std::cout << "У игрока " << name << " перебор :(" << std::endl; }

private:
    std::string name{"No name"};
};

