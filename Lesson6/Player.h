#pragma once

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string& name) :
        GenericPlayer(name)
    {}

    virtual bool IsHitting() const
    {
        char c = GetUserInput<char>(name + ", хотите взять карту?");
        return (c=='y' || c=='Y');
    };

    void Win() const { std::cout << name + " выиграл!!!" << std::endl; }
    void Lose() const { std::cout << name + " проиграл!!!" << std::endl; }
    void Push() const { std::cout << "Ничья!!!" << std::endl; }
};

