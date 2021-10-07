#pragma once

#include "Common.h"
#include "Task1.h"
#include "Task2.h"
#include "Player.h"
#include "House.h"

class Lesson
{
public:
    void Task1();
    void Task2();
    void BlackjackTest();
};

template<typename T>
class Foo {
public:
    Foo();
    void someMethod(T x);
private:
    T x;
};