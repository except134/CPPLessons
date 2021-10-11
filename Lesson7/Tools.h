#pragma once

template<typename T>
T GetUserInput(const std::string& prompt, int length = 1)
{
    while(true) {
        T val;

        std::cout << prompt << ": ";
        std::cin >> val;

        if (std::cin.fail() || (std::to_string(val).length() > length && !std::is_same<T, char>::value)) {
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
