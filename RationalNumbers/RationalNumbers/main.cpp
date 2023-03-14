//
//  main.cpp
//  RationalNumbers
//
//  Created by Sergio Enrico Coppolecchia on 08/03/23.
//
#include <cassert>
#include <iostream>
#include <numeric>

struct rational
{
    rational()
    : rational{0, 1}
    {/* empty */}
    
    rational(int num)
    : numerator{num}, denominator{1}
    {/* empty */}
    
    rational(int num, int den)
    : numerator {num}, denominator{den}
    {
        reduce();
    }
    
    rational (double r)
    : rational{static_cast<int>(r * 100000), 100000}
    {/* empty */}
    
    rational& operator=(rational const&) = default;
    
    rational& operator=(int number)
    {
        this->numerator = number;
        this->denominator = 1;
        reduce();
        return *this;
    }
    
    void assign(int num, int den)
    {
        numerator = num;
        denominator = den;
        reduce();
    }
    
    void reduce()
    {
        assert(denominator != 0);
        if (denominator < 0)
        {
            denominator = - denominator;
            numerator = -numerator;
        }
        int div{std::gcd(numerator, denominator)};
        numerator = numerator / div;
        denominator = denominator / div;
    }
    
    float as_float()
    {
        return static_cast<float>(numerator) / denominator;
    }
    
    double as_double()
    {
        return numerator / static_cast<double>(denominator);
    }
    
    long double as_long_double()
    {
        return static_cast<long double>(numerator) / static_cast<long double>(denominator);
    }
    
    int numerator;
    int denominator;
};

bool operator==(rational const& a, rational const& b)
{
    return a.numerator == b.numerator and a.denominator == b.denominator;
}

inline bool operator!=(rational const& a, rational const& b)
{
    return not (a==b);
}

bool operator<(rational const& a, rational const& b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

inline bool operator<=(rational const& a, rational const& b)
{
    return not (b < a);
}

inline bool operator>(rational const& a, rational const& b)
{
    return b < a;
}

inline bool operator>=(rational const& a, rational const& b)
{
    return not (b > a);
}

rational operator+(rational const& lhs, rational const& rhs)
{
    return rational{
        lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator
    };
}

rational operator-(rational const& r)
{
    return rational{-r.numerator, r.denominator};
}

rational operator-(rational const& lhs, rational const& rhs)
{
    return rational{
        lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator
    };
}

rational operator*(rational const& lhs, rational const& rhs)
{
    return rational{
        lhs.numerator * rhs.numerator,
        lhs.denominator * rhs.denominator
    };
}

rational operator/(rational const& lhs, rational const& rhs)
{
    return rational{
        lhs.numerator * rhs.denominator,
        lhs.denominator * rhs.numerator
    };
}

rational operator*(rational const& rat, int mult)
{
    return rational{rat.numerator * mult, rat.denominator};
}

inline rational operator*(int mult, rational const& rat)
{
    return rat * mult;
}

rational absval(rational const& r)
{
    return rational{std::abs(r.numerator), r.denominator};
}

std::istream& operator>>(std::istream& in, rational& rat)
{
    int n{0}, d{0};
    char sep{'\0'};
    
    if (not (in >> n >> sep))
        in.setstate(std::cin.failbit);
    else if (sep != '/')
    {
        in.unget();
        rat.assign(n, 1);
    }
    else if (in >> d)
        rat.assign(n, d);
    else
        in.setstate(std::cin.failbit);
    
    return in;
}

std::ostream& operator<<(std::ostream& out, rational const& rat)
{
    out << rat.numerator;
    if (rat.denominator != 1)
        out << '/' << rat.denominator;
    return out;
}

int main(int argc, const char * argv[]) {
    rational result{3 * rational{1,5}};
    
    std::cout << result;
    
    return 0;
}
