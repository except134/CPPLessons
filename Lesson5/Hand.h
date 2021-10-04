#pragma once

#include "Card.h"

class Hand
{
public:
    Hand() = default;

    void Add(Card* c)
    {
        assert(c != nullptr);
        cards.emplace_back(c);
    }

    void Clear()
    {
        cards.clear();
    }

    int GetValue()
    {
        int total = 0;
        for(auto c: cards) {
            total += c->GetNominal();
            if(total <= 11 && c->GetFace() == CardFace::Ace)
                total += 10;
        }
        return total;
    }

    void Open()
    {
        for(auto c: cards) {
            c->Open();
        }
    }

    void Show()
    {
        for(auto c: cards) {
            c->Show();
        }
        std::cout << std::endl;
    }

private:
    std::vector<Card*> cards{};
};
