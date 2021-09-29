#pragma once

enum ExitCode
{
    NoError,
    DevisionByZero,
    IntegerOverflow
};

class Fraction
{
public:
    Fraction() = default;
    Fraction(const Fraction &) = default;
    Fraction &operator=(const Fraction &) = default;
    Fraction(int64_t num, int64_t denom) { SetValue(num, denom); }

    void SetValue(int64_t num, int64_t denom)
    {
        if(denom == 0)
        {
            std::cerr << "Ошибка! Знаменатель не может равняться нулю. (Файл: " << __FILE__ << ", строка: " << __LINE__ << ")" << std::endl;
            std::cerr << "\t" << num << "/" << denom << std::endl;
            exit(ExitCode::DevisionByZero);
        } else if(num == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            int sign = 1;

            if(CheckOverflow(num) < 0) {
                sign *= -1;
                num *= -1;
            }
            if(CheckOverflow(denom) < 0) {
                sign *= -1;
                denom *= -1;
            }

            int64_t divisor = GreatestCommonDivisor(num, denom);
            numerator  = num / (divisor * sign);
            denominator  = denom / divisor;
        }
    }

    int64_t GetNumerator() const { return numerator; }
    int64_t GetDenominator() const { return denominator; }

    Fraction &operator++()
    {
        numerator++;
        denominator++;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction old = *this;
        numerator++;
        denominator++;
        return old;
    }

    Fraction &operator--()
    {
        numerator--;
        denominator--;
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction old = *this;
        numerator--;
        denominator--;
        return old;
    }

    Fraction &operator+=(const Fraction& other) { return *this = *this + other; }
    Fraction &operator+=(const int64_t& s) { return *this = *this + s; }
    Fraction &operator*=(const Fraction& other) { return *this = *this * other; }
    Fraction &operator*=(const int64_t& s) { return *this = *this * s; }
    Fraction &operator/=(const Fraction& other) { return *this = *this / other; }
    Fraction &operator/=(const int64_t& s) { return *this = *this / s; }
    Fraction &operator-=(const Fraction& other) { return *this = *this - other; }
    Fraction &operator-=(const int64_t& s) { return *this = *this - s; }

    operator float()  { return (static_cast<float>(numerator))/denominator; }
    operator double() { return (static_cast<double>(numerator))/denominator; }

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator+(const Fraction& f, const int64_t& s);
    friend Fraction operator+(const int64_t& s, const Fraction& f);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& f, const int64_t& s);
    friend Fraction operator-(const int64_t& s, const Fraction& f);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& f, const int64_t& s);
    friend Fraction operator*(const int64_t& s, const Fraction& f);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& f, const int64_t& s);
    friend Fraction operator/(const int64_t& s, const Fraction& f);
    friend bool     operator<(const Fraction& lhs, const Fraction& rhs);
    friend bool     operator>(const Fraction& lhs, const Fraction& rhs);
    friend bool     operator==(const Fraction& lhs, const Fraction& rhs);
    friend bool     operator!=(const Fraction& lhs, const Fraction& rhs);
    friend bool     operator>=(const Fraction& lhs, const Fraction& rhs);
    friend bool     operator<=(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& stream, const Fraction& obj);

    void Print()
    {
        if(denominator == 1)
            std::cout << numerator;
        else
            std::cout << numerator << "/" << denominator;
    }

private:
    int64_t CheckOverflow(int64_t x)
    {
        if((x > std::numeric_limits<int64_t>::max()) || (x < std::numeric_limits<int64_t>::min())) {
            std::cerr << "Ошибка! Целочисленное переполнение." << std::endl;
            exit(ExitCode::IntegerOverflow);
        } else {
            return x;
        }
    }

    int64_t GreatestCommonDivisor(int64_t x, int64_t y)
    {
        if(x == 0) {
            return y;
        }
        return GreatestCommonDivisor(y%x, x);
    }

    Fraction Invert() const
    {
        if(numerator == 0 ) {
            std::cout  << "Не могу инвертировать ноль." << std::endl;
            return Fraction(numerator, denominator);
        } else {
            return Fraction(denominator, numerator);
        }
    }

private:
    int64_t numerator{1};
    int64_t denominator{1};
};

inline Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction frac;

    frac.numerator = lhs.numerator * rhs.denominator + rhs.numerator * lhs.numerator;
    frac.denominator = lhs.denominator * rhs.denominator;

    return frac;
}

inline Fraction operator+(const Fraction& f, const int64_t& s)
{
    Fraction temp(s, 1);
    return f + temp;
}

inline Fraction operator+(const int64_t& s, const Fraction& f)
{
    return f + s;
}

inline Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    Fraction frac;

    frac.numerator = lhs.numerator * rhs.denominator - rhs.numerator * lhs.numerator;
    frac.denominator = lhs.denominator * rhs.denominator;

    return frac;
}

inline Fraction operator-(const Fraction& f, const int64_t& s)
{
    Fraction temp(s, 1);
    return f - temp;
}

inline Fraction operator-(const int64_t& s, const Fraction& f)
{
    return int64_t(-1) * (f - s);
}

inline Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    Fraction frac;

    frac.numerator = lhs.numerator * rhs.numerator;
    frac.denominator = lhs.denominator * rhs.denominator;

    return frac;
}

inline Fraction operator*(const Fraction& f, const int64_t& s)
{
    return Fraction(f.numerator * s, f.denominator);
}

inline Fraction operator*(const int64_t& s, const Fraction& f)
{
    return f * s;
}

inline Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    Fraction frac;

    frac.numerator = lhs.numerator * rhs.denominator;
    frac.denominator = lhs.denominator * rhs.numerator;

    return frac;
}

inline Fraction operator/(const Fraction& f, const int64_t& s)
{
    Fraction temp(s, 1);
    return f / temp;
}

inline Fraction operator/(const int64_t& s, const Fraction& f)
{
    Fraction temp = f / s;
    return temp.Invert();
}

inline bool operator<(const Fraction& lhs, const Fraction& rhs)
{
    return ((lhs.numerator * rhs.denominator) - (rhs.numerator * lhs.denominator)) < 0;
}

inline bool operator>(const Fraction& lhs, const Fraction& rhs)
{
    return ((lhs.numerator * rhs.denominator) - (rhs.numerator * lhs.denominator)) > 0;
}

inline bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}

inline bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}

inline bool operator>=(const Fraction& lhs, const Fraction& rhs)
{
    return (lhs > rhs) || (lhs == rhs);
}

inline bool operator<=(const Fraction& lhs, const Fraction& rhs)
{
    return (lhs < rhs) or (lhs == rhs);
}

inline std::ostream& operator<<(std::ostream& stream, const Fraction& obj)
{
    if(obj.denominator == 1) {
        stream << obj.numerator;
    } else {
        stream << obj.numerator << "/" << obj.denominator;
    }
    return stream;
}
