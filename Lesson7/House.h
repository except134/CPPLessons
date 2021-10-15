#pragma once

class House : public GenericPlayer
{
public:
    House(const std::string& name = "Dealer") :
        GenericPlayer(name)
    {}

    virtual ~House() {};

    void OpenFirstCard()
    {
        if(!(cards.empty())) {
            cards[0]->Open();
        } else {
            std::cout << "Карты отсутствуют!" << std::endl;
        }
    }

    virtual bool IsHitting() const
    {
        const int DecisionPoints = 16;

        return (GetTotal() <= DecisionPoints);
    };

};

