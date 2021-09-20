#pragma once

class Person
{
public:
    Person() = default;
    Person(const std::string& n, int a, bool isW, int m) :
        name(n),
        age(a),
        isWoman(isW),
        mass(m)
        {};

    void Set(const std::string& n, int a, bool isW, int m)
    {
        name = n;
        age = a;
        isWoman = isW;
        mass = m;
    }

    const std::string& GetName() const { return name; }

    void Print()
    {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Пол: " << (isWoman?"Жен.":"Муж.") << std::endl;
        std::cout << "Вес: " << mass << std::endl;
    }

private:
    std::string name{};
    int age{0};
    bool isWoman{false};
    int mass{0};
};

class Student : public Person
{
public:
    Student() = default;
    Student(const std::string& n, int a, bool isW, int m, int year) :
        Person(n, a, isW, m),
        yearOfStudy(year)
    {}

    int GetYear() const { return yearOfStudy; }
    void SetYear(int year) { yearOfStudy = year; }

    void Print()
    {
        Person::Print();
        std::cout << "Год обучения: " << yearOfStudy << std::endl;
    }

private:
    int yearOfStudy{0};
};

class StudentsProcess
{
public:
    void Run()
    {
        students.push_back(Student("Студент 1", 20, false, 75, 2021));
        students.push_back(Student("Студент 2", 21, false, 65, 2020));
        students.push_back(Student("Студент 3", 18, false, 55, 2019));
        students.push_back(Student("Студентка 1", 19, true, 60, 2018));
        students.push_back(Student("Студентка 2", 22, true, 58, 2017));
        students.push_back(Student("Студентка 3", 20, true, 57, 2021));

        for(auto a: students) {
            a.Print();
            std::cout << std::endl;
        }

        std::string name;
        std::cout << "Введите имя искомого студента: ";
        std::getline(std::cin, name);

        bool found = false;
        for(auto a: students) {
            if(a.GetName() == name) {
                found = true;
                std::cout << "Студент найден:" << std::endl;
                a.Print();
                break;
            }
        }

        if(!found)
            std::cout << "Студент не найден." << std::endl;

        std::cout << std::endl;
    }

private:
    std::vector<Student> students;
};
