#include "Lesson.h"

class DivisionByZeroException
{
public:
    DivisionByZeroException(std::string msg = "", std::string file = "", int line = 0) :
        message(msg),
        fileName(file),
        lineNumber(line)
        {
            fullMessage = "Исключительная ситуация: " + message + " (File: " + fileName + ", line: " + std::to_string(lineNumber) + ")";
        }

    virtual const std::string& GetMessage() const
    {
        return fullMessage;
    }

protected:
    std::string fullMessage{};
    std::string message{};
    std::string fileName{};
    int lineNumber{0};
};

template <typename T>
double Div(T a, T b)
{
    if (b == 0)
        throw DivisionByZeroException("Эта грустная история о прекрасной восточной\n"
                                      "девушке Наноль, которая любит двоих прекрасных и\n"
                                      "мужественных юношей и не может выбрать.\n"
                                      "Юноши тоже любят ее. Казалось бы, в нынешние-то времена,\n"
                                      "зажить бы им простой и дружной семьей. Но трагедия в том,\n"
                                      "что Наноль делить нельзя.\n", __FILE__, __LINE__);

    return a / b;
}

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    try
    {
        double result = Div(10, 0);
        std::cout << result << std::endl;
    }
    catch (const DivisionByZeroException& e)
    {
        std::cout << e.GetMessage();
    }

    std::cout << endll;
}

/////////////////////////////////////////////////////

class Ex
{
public:
    Ex(double X) : x(X) {};

public:
    double x;
};

class Bar
{
public:
    Bar(double Y = 0.0) : y(Y) {}

    void Set(double a)
    {
        if ((y + a) > 100)
            throw Ex(a * y);
        else
            y = a;
    }

private:
    double y;
};

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    Bar a;
    int b;

    try {
        while (true) {
            b = GetUserInput<int>("Введите целое число");
            if (b == 0)
                break;
            a.Set(b);
        }
    }
    catch (const Ex& e)
    {
        std::cout << e.x << std::endl;
    }

    std::cout << std::endl;
}

/////////////////////////////////////////////////////

const int CELL_SIZE = 10;

class RobotException
{
public:
    RobotException(int curX, int curY, int newX, int newY) :
            currentPositionX(curX),
            currentPositionY(curY),
            newPositionX(newX),
            newPositionY(newY),
            message("")
    {}

    const std::string& GetInfo() const
    {
        return message;
    }

    const std::string& GetCoordinates()
    {
        coords = "из (" +
                std::to_string(currentPositionX) + ", " + std::to_string(currentPositionY) +
                ") в (" +
                std::to_string(newPositionX) + ", " + std::to_string(newPositionY) + ")";

        return coords;
    }

protected:
    int currentPositionX{0};
    int currentPositionY{0};
    int newPositionX{0};
    int newPositionY{0};
    std::string message{};
    std::string coords{};
};

class OffTheField : public RobotException
{
public:
    OffTheField(int curX, int curY, int newX, int newY) :
            RobotException(curX, curY, newX, newY)
    {
        if(newPositionX > CELL_SIZE || newPositionX < 1) {
            message = "Ошибка выхода за границы по оси Х " + GetCoordinates();
        }

        if (newPositionY > CELL_SIZE || newPositionY < 1) {
            message = "Ошибка выхода за границы по оси Y " + GetCoordinates();
        }
    }
};

class IllegalCommand : public RobotException
{
public:
    IllegalCommand(int curX, int curY, int newX, int newY) :
            RobotException(curX, curY, newX, newY)
    {
        if (std::abs(currentPositionX - newPositionX) > 1) {
            message = "Слишком большой шаг по оси Х " + GetCoordinates();
        }

        if (std::abs(currentPositionY - newPositionY) > 1) {
            message = "Слишком большой шаг по оси Y " + GetCoordinates();
        }

        if (currentPositionX == newPositionX && currentPositionY == newPositionY) {
            message = "Нельзя ходить в место, в котором находишься " + GetCoordinates();
        }
    }
};

class Robot
{
public:
    Robot(int x = CELL_SIZE / 2, int y = CELL_SIZE / 2) :
        positionX(x),
        positionY(y)
    {
        std::cout << "Стартуем в позиции " << positionX << ", " << positionY << std::endl;
    }

    void Move(int x, int y)
    {
        if (abs(positionX - x) > 1 || abs(positionY - y) > 1 || (positionX == x && positionY == y))
            throw IllegalCommand(positionX, positionY, x, y);
        if (x > CELL_SIZE || x < 1 || y > CELL_SIZE || y < 1)
            throw OffTheField(positionX, positionY, x, y);

        std::cout << "Идем из (" << positionX << ", " << positionY << ") в (" << x << ", " << y << ")" << std::endl;

        positionX = x;
        positionY = y;
    }

private:
    int positionX{};
    int positionY{};
};

void Lesson::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;

    int x = 0, y = 0;
    Robot robot;

    while (true) {
        std::cout << "Введите 0 в Х и Y для выхода." << std::endl;
        x = GetUserInput<int>("Введите позицию по Х");
        y = GetUserInput<int>("Введите позицию по Y");

        if (x == 0 && y == 0)
            break;

        try {
            robot.Move(x, y);
        }
        catch(const IllegalCommand& e) {
            std::cout << e.GetInfo() << std::endl;
        }
        catch (const OffTheField& e) {
            std::cout << e.GetInfo() << std::endl;
        }
    }
}

