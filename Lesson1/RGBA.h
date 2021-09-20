#pragma once

class RGBA
{
public:
    RGBA() : red(0), green(0), blue(0), alpha(255) {}
    RGBA(uint8 r, uint8 g, uint8 b, uint8 a) : red(r), green(g), blue(b), alpha(a) {}

    void Print()
    {
        std::cout << "Красный = " << static_cast<uint16>(red) << std::endl;
        std::cout << "Зеленый = " << static_cast<uint16>(green) << std::endl;
        std::cout << "Голубой = " << static_cast<uint16>(blue) << std::endl;
        std::cout << "Альфа = " << static_cast<uint16>(alpha) << std::endl;
    }

private:
    uint8 red{0};
    uint8 green{0};
    uint8 blue{0};
    uint8 alpha{255};
};
