#include "Rational.h"
using namespace std;

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(int number) {
    numer = number;
    denom = 1;
}
Rational::Rational(int n, int d) {
    numer = n;
    denom = d;
}

int Rational::gcd(int a, int b) const {
    if (a % b == 0)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, a - b);
}
    
Rational& Rational::operator +=(const Rational& r) {
    numer = (numer * r.denom + denom * r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}

void Rational::simplify() {
    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
    for (int i=2; i<=abs(denom) && i<=abs(numer); i++)
        if (numer % i == 0 && denom % i == 0) {
            numer /= i;
            denom /= i;
            i--;
        }
}

Rational Rational::operator +(const Rational& r) const {
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const {
    Rational r(-numer, denom);
    return r;
}

Rational Rational::operator -=(const Rational& r) {
    return (*this += (-r));
}

Rational& Rational::operator ++() {
    numer += denom;
    return *this;
}

Rational Rational::operator ++(int) {
    Rational r(*this);
    numer += denom;
    return r;
}

bool Rational::operator==(const Rational& r) const {
    return (numer == r.numer) && (denom == r.denom);
}
bool Rational::operator !=(const Rational& r) const {
    return !(*this == r);
}

Rational::operator int() const {
    return numer / denom;
}
Rational::operator double() const {
    return ((double)numer) / denom;
}

istream& operator >>(istream& in, Rational& r) {
    in >> r.numer >> r.denom;
    return in;
}

ostream& operator <<(ostream& out, Rational& r) {
    out << r.numer <<"/" << r.denom;
    return out;
}

void Rational::display() const {
    cout << numer << "/" << denom << endl;
}
