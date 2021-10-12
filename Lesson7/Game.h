#pragma once

class Game
{
public:
    Game(const std::vector<std::string>& names)
    {
        for (const auto& pName : names) {
            players.emplace_back(Player(pName));
        }

        deck.Populate();
        deck.Shuffle();
    }

    ~Game() {};

    void Play();

private:
    Deck deck;
    House house;
    std::vector<Player> players;
};

inline void Game::Play()
{
    for (int i = 0; i < 2; ++i) {
        for (auto& pPlayer: players) {
            deck.Deal(pPlayer);
        }
        deck.Deal(house);
    }

    house.OpenFirstCard();

    for (const auto& pPlayer: players) {
        std::cout << pPlayer << std::endl;
    }
    std::cout << house << std::endl;

    for (auto& pPlayer: players) {
        deck.AdditionalCards(pPlayer);
    }

    house.OpenFirstCard();
    std::cout << std::endl << house;

    deck.AdditionalCards(house);

    if (house.IsBusted()) {
        for (auto& pPlayer: players) {
            if (!(pPlayer.IsBusted())) {
                pPlayer.Win();
            }
        }
    } else {
        for (auto& pPlayer: players) {
            if (!(pPlayer.IsBusted())) {
                if (pPlayer.GetTotal() > house.GetTotal()) {
                    pPlayer.Win();
                } else if (pPlayer.GetTotal() < house.GetTotal()) {
                    pPlayer.Lose();
                } else {
                    pPlayer.Push();
                }
            }
        }

    }

    for (auto& pPlayer: players) {
        pPlayer.Clear();
    }
    house.Clear();
}
