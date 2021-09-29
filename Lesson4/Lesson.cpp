#include "Lesson.h"

void Lesson::Task1()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 1" << std::endl;
    std::cout << "=========================" << std::endl;

    const size_t ARR_SIZE = 20;

    std::cout << "Массив                  : ";
    ArrayInt arr;

    for(int i = 0; i < ARR_SIZE; ++i)
        arr.push_back(i + 1);

    arr.print();


    std::cout << "Уменьшаем размер на 10  : ";
    arr.resize(ARR_SIZE - 10);
    arr.print();

    std::cout << "Убираем два последних   : ";
    arr.pop_back();
    arr.pop_back();
    arr.print();

    std::cout << "Убираем два первых      : ";
    arr.pop_front();
    arr.pop_front();
    arr.print();

    std::cout << "Вставляем в 3 позицию 99: ";
    arr.insertBefore(99, 2);
    arr.print();

    std::cout << std::endl;

    std::cout << "Сгенерированный массив  : ";

    std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, 100);

    arr.erase();

    for(int i = 0; i < ARR_SIZE; ++i)
        arr.push_back(dist(rnd));

    arr.print();

    std::cout << "Отсортированный массив  : ";
    arr.sort();
    arr.print();

    std::cout << std::endl;
}

void Lesson::Task2()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 2" << std::endl;
    std::cout << "=========================" << std::endl;

    const size_t ARR_SIZE = 30;

    std::default_random_engine rnd(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, 100);

    auto Print = [&](auto& v) {
        std::cout << "(";
        for(int index = 0; index < v.size(); ++index) {
            if(index != 0)
                std::cout << ", ";
            std::cout << v[index];
        }
        std::cout << ")" << std::endl;
    };

    std::cout << "Генерируем массив на " << ARR_SIZE << " элементов." << std::endl;
    std::cout << "Сгенерированный массив  : ";
    std::vector<int> arr(ARR_SIZE);
    std::generate(arr.begin(), arr.end(), [&]() { return dist(rnd); });
    Print(arr);

    std::cout << "Отсортированный массив  : ";
    std::sort(arr.begin(), arr.end());
    Print(arr);

    int diff = std::unique(arr.begin(), arr.end()) - arr.begin();
    std::cout << "Различных чисел         : " << diff << std::endl;

    std::cout << std::endl;
}

void Lesson::Task3()
{
    std::cout << "=========================" << std::endl;
    std::cout << "Задача 3" << std::endl;
    std::cout << "=========================" << std::endl;

    Card KingHeart{CardFace::King, CardSuit::Heart};
    Card AceClub{CardFace::Ace, CardSuit::Club};
    Card TwoSpade{CardFace::Two, CardSuit::Spade};
    Card AceDiamond{CardFace::Ace, CardSuit::Diamond};

    Hand hand;
    hand.Add(&KingHeart);
    hand.Add(&AceClub);
    hand.Add(&TwoSpade);
    hand.Add(&AceDiamond);

    std::cout << "Изначальный расклад карт: ";
    hand.Show();

    std::cout << "Открытые карты          : ";
    hand.Open();
    hand.Show();

    std::cout << "Сумма очков             : " << hand.GetValue();

    std::cout << std::endl;
}

