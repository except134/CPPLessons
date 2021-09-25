#pragma once

const int KEY_EXIT = 'q';

enum class CardFace : int
{
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
    Jack,
    Queen,
    King,
    Max
};

enum class CardSuit : int
{
    Heart,
    Spade,
    Club,
    Diamond,
    Max
};

class Card
{
public:
    Card() = default;
    Card(CardFace f, CardSuit s, bool opened = false) :
        face(f),
        suit(s),
        isOpened(opened)
    {
    }

    int Open() { isOpened = true; return GetNominal(); }
    bool IsOpened() { return isOpened; }
    CardFace GetFace() { return face; }

    int GetNominal()
    {
        if(face >= CardFace::Ace && face <= CardFace::Nine)
            return static_cast<int>(face) + 1;
        else if(face >= CardFace::Ten && face <= CardFace::King)
            return 10;

        return 0;
    }

    void Show()
    {
        std::cout << (isOpened ? facesChar[static_cast<size_t>(face)] : "X") << " ";
    }

private:
    bool isOpened{false};
    CardFace face{CardFace::Max};
    CardSuit suit{CardSuit::Heart};
    const char* facesChar[static_cast<size_t>(CardFace::Max)]{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
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

    Card GetCard()
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
        for(auto& c: cards) {
            int r = c.Open();
            if(c.GetFace() == CardFace::Ace && sumOfCards == 20)
                r = 1;
            sumOfCards += r;
        }
    }

    void ShowCards()
    {
        for(auto& c: cards)
            c.Show();
    }

    void ShowPoints()
    {
        std::cout << sumOfCards;
    }

    void GetCardsFromDeck(Deck& deck, int count)
    {
        for(int i = 0; i < count; ++i) {
            cards.emplace_back(deck.GetCard());
        }
    }

    void Reset()
    {
        cards.clear();
        sumOfCards = 0;
    }

private:
    std::vector<Card> cards;
    int sumOfCards{0};
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
        bool done = false;

        deck.Initialize();
        deck.Shuffle();

        player.GetCardsFromDeck(deck, 3);

        dealer.GetCardsFromDeck(deck, 5);
        dealer.OpenAllCards();

        while(!done) {
            Show();

            int keyPressed = getchar();

            if(keyPressed == KEY_EXIT)
                done = true;

        }
    }

    void Show()
    {
        system("clear");

        std::cout << "========== BLACK JACK ==========" << std::endl << std::endl;
        std::cout << "  Карты диллера: ";
        dealer.ShowCards();
        std::cout << std::endl;
        std::cout << "  Очки диллера: ";
        dealer.ShowPoints();
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "  Карты игрока: ";
        player.ShowCards();
        std::cout << std::endl;
        std::cout << "  Очки игрока: ";
        player.ShowPoints();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void ProcessInput()
    {

    }

private:
    Player player;
    Dealer dealer;
    Deck deck;
};

