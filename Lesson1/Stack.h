#pragma once

const size_t ARRAY_SIZE = 10;

class Stack
{
public:
    Stack() = default;

    bool Push(int val)
    {
        if(arrayLength >= ARRAY_SIZE)
            return false;

        array[arrayLength++] = val;

        return true;
    }

    int Pop()
    {
        if(arrayLength==0) {
            std::cout << "Стэк пустой." << std::endl;
            return 0;
        }

        return array[arrayLength--];
    }

    void Reset()
    {
        arrayLength = 0;
        for(size_t i = 0; i < ARRAY_SIZE; ++i)
            array[i] = 0;
    }

    void Print()
    {
        std::cout << "( ";
        for(size_t i = 0; i < arrayLength; ++i)
            std::cout << array[i] << " ";
        std::cout << ")" << std::endl;
    }

private:
    size_t arrayLength{0};
    int array[ARRAY_SIZE]{0};
};
