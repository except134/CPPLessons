#pragma once

class Deck : public Hand
{
public:
    Deck()
    {
        cards.reserve(DeckSize);
        Populate();
    }

    void Populate()
    {
        Clear();

        for(int s = 0; s < static_cast<int>(CardSuit::Max); ++s) {
            for(int f = 0; f < static_cast<int>(CardFace::Max); ++f) {
                Add(new Card(static_cast<CardFace>(f), static_cast<CardSuit>(s)));
            }
        }
    }

    void Shuffle()
    {
        std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(cards.begin(), cards.end(), rnd);
    }

    void Deal(Hand& hand)
    {
        if(!cards.empty()) {
            hand.Add(cards.back());
            cards.pop_back();
        } else {
            std::cout << "Колода пуста. Нечего выдавать.";
        }
    }

    void AdditionalCards(GenericPlayer& genericPlayer)
    {
        std::cout << std::endl;

        while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
        {
            Deal(genericPlayer);
            std::cout << genericPlayer << std::endl;

            if (genericPlayer.IsBusted()) {
                genericPlayer.Bust();
            }
        }
    }

private:
    const int DeckSize{52};
};
