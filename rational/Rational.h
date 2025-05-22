#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>

class Rational {
private:
    int numer; // Числитель
    int denom; // Знаменатель

    int gcd(int a, int b) const;
    
    void simplify();

public:
    Rational();

    Rational(int number);

    Rational(int n, int d);

    Rational& operator +=(const Rational& r);

    Rational operator +(const Rational& r) const;

    Rational operator-() const;

    Rational operator -=(const Rational& r);

    Rational& operator ++();

    Rational operator ++(int);

    bool operator ==(const Rational& r) const;
    bool operator !=(const Rational& r) const;

    operator int() const;
    operator double() const;

    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator <<(ostream& out, Rational& r);
    
    void display() const;
};

#endif
