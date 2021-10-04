#pragma once

#include "Hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const std::string& n) : name(n) {}
    virtual ~GenericPlayer(){};

    virtual bool IsHitting() const = 0;

    bool IsBoosted() { return (GetTotal() > PointsToWin); }
    void Bust() { std::cout << "У игрока " << name << " перебор :(" << std::endl; }

    friend std::ostream& operator<<(std::ostream& stream, const GenericPlayer& p);

protected:
    std::string name{"No name"};
    static const int PointsToWin{21};
};

inline std::ostream& operator<<(std::ostream& stream, const GenericPlayer& p)
{
    stream << "У игрока " + p.name + ": ";

    if(p.cards.empty()) {
        stream << "Карт нету.";
    } else {
        for(auto c: p.cards) {
            stream << *c << "\t";
        }

        stream << "Очков: " << p.GetTotal() << std::endl;

    }

    return stream;
}
