#pragma once

template<typename T>
T GetUserInput(const std::string& prompt)
{
    while(true) {
        T val;

        std::cout << prompt << ": ";
        std::cin >> val;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<T>::max(), '\n');
            std::cout << "Некорректный ввод.  Попробуйте снова." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<T>::max(), '\n');
            return val;
        }
    }
}

inline std::ostream& endll(std::ostream& stream)
{
    stream << "\n\n" << std::flush;
    return stream;
}

inline int EnterNumber(const std::string& prompt)
{
    int input;
    while (true)
    {
        std::cout << prompt << ": " << std::flush;
        std::string line;
        if (!getline(std::cin, line)) {
            std::cerr << "Критическая ошибка!!!" << std::endl;
            return std::numeric_limits<int>::min();
        }
        std::istringstream line_stream(line);
        char extra;
        if (line_stream >> input && !(line_stream >> extra))
            break;
        else
            std::cout << "Не верный ввод. Повторите." << std::endl;
    }
    std::cout << input << std::endl;
    return input;
}
