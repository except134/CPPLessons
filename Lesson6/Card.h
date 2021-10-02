#pragma once

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
    void Flip() { isOpened = !isOpened; }

    int GetNominal()
    {
        if(face >= CardFace::Ace && face <= CardFace::Nine)
            return static_cast<int>(face) + 1;
        else if(face >= CardFace::Ten && face <= CardFace::King)
            return 10;

        return 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& c);

private:
    bool isOpened{false};
    CardFace face{CardFace::Max};
    CardSuit suit{CardSuit::Max};
};

inline std::ostream& operator<<(std::ostream& os, const Card& c)
{

    if(c.isOpened) {
        os << facesChar[c.face] << suitsChar[c.suit];
    } else {
        os << "XX";
    }

    return os;
}
