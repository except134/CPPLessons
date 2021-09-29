#pragma once

class Figure
{
public:
    Figure() = default;

    virtual double Area() = 0;
    virtual void Print() {};
};

class Parallelogram : public Figure
{
public:
    Parallelogram() = default;
    Parallelogram(double h, double l) :
        height(h),
        width(l)
    {}

    void SetHeight(double h) { height = h; }
    void SetWidth(double l) { width = l; }

    void SetParams(double h, double l)
    {
        height = h;
        width = l;
    }

    virtual double Area()
    {
        return width * height;
    }

    virtual void Print()
    {
        std::cout << "Площадь параллелограмма ("
                     << "высота: " << height
                     << " основание: " << width
                     << ") = "
                     << Area()
                     << std::endl;
    }

protected:
    double height{0};
    double width{0};
};

class Circle : public Figure
{
public:
    Circle() = default;
    Circle(double rad) : radius(rad) {}

    void SetRadius(double rad)
    {
        radius = rad;
    }

    virtual double Area()
    {
        return radius * radius * Pi;
    }

    virtual void Print()
    {
        std::cout << "Площадь круга ("
                  << "радиус: " << radius
                  << ") = "
                  << Area()
                  << std::endl;
    }

private:
    double radius{0};
    const double Pi{3.14159265};
};

class Rectangle : public Parallelogram
{
public:
    Rectangle() = default;
    Rectangle(double x, double y) : Parallelogram(x, y) {}

    virtual void Print()
    {
        std::cout << "Площадь прямоугольника ("
                  << "высота: " << height
                  << " ширина: " << width
                  << ") = "
                  << Area()
                  << std::endl;
    }
};

class Square : public Parallelogram
{
public:
    Square() = default;
    Square(double x) : Parallelogram(x, x) {}

    virtual void Print()
    {
        std::cout << "Площадь квадрата ("
                  << "сторона: " << height
                  << ") = "
                  << Area()
                  << std::endl;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus() = default;
    Rhombus(double s) : Parallelogram(s, s) {}

    virtual void Print()
    {
        std::cout << "Площадь ромба ("
                  << "сторона: " << height
                  << ") = "
                  << Area()
                  << std::endl;
    }
};
