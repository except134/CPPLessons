#pragma once

enum class CardFace : int
{
    Zero,
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Vallet,
    Dama,
    King,
    Max
};

enum class CardSuit : int
{
    Heart,
    Spade,
    Cross,
    Diamond,
    Max
};

enum class CardPlace : int
{
    Player,
    Dealer,
    Deck
};

class Card
{
public:
    Card() = default;
    Card(CardFace f, CardSuit s, CardPlace p = CardPlace::Deck, bool opened = false) :
        face(f),
        suit(s),
        place(p),
        isOpened(opened)
    {
    }

    void Flip()
    {
        isOpened =! isOpened;
    }

    bool IsOpened() { return isOpened; }
    CardFace GetFace() { return face; }
    CardPlace GetPlace() { return place; }
    void MoveToPlace(CardPlace p) { place = p; }

private:
    bool isOpened{false};
    CardFace face{CardFace::Zero};
    CardSuit suit{CardSuit::Heart};
    CardPlace place{CardPlace::Deck};
};

class Deck
{
public:
    Deck() = default;

    // В некоторых правилах в игре могут учавствоать несколько колод карт.
    // По умолчанию играем с одной колодой.
    void Initialize(int countOfDecks = 1)
    {
        deck.clear();

        for(int n = 0; n < countOfDecks; ++n) {
            for(int s = 0; s < static_cast<int>(CardSuit::Max); ++s) {
                for(int f = 0; f < static_cast<int>(CardFace::Max); ++f) {
                    deck.emplace_back(Card(static_cast<CardFace>(f), static_cast<CardSuit>(s)));
                }
            }
        }
    }

    void Shuffle()
    {
        std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(deck.begin(), deck.end(), rnd);
    }

    Card GetTopCard()
    {
        Card ret = deck.back();
        deck.pop_back();
        return ret;
    }

    size_t TotalCardsInGame() { return deck.size(); }

private:
    std::vector<Card> deck;
};

class Player
{
public:
    Player() = default;

    void OpenAllCards()
    {
    }

    void ShowCards()
    {
    }

    void GetCardsFromDeck(const Deck& deck, int count)
    {
    }

    void Reset()
    {
        cards.clear();
    }

private:
    std::vector<Card> cards;
};

class Dealer : public Player
{
public:
    Dealer() = default;
};

class Game
{
public:
    void Run()
    {
    }

private:
    Player player;
    Dealer dealer;
};

