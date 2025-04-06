#include <iostream>
#include "Rational.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    
    Rational a(1, 2), b(1, 6);
    cout << "Тестирования №1 " << endl;
    cout << "a=" << a << "b=" << b << " a+b" << a + b<<endl;
    cout << "a(" << a << ") *= b(" << b << ")" << endl;
    a *= b;

    cout << "Тестирования №2 " << endl;
    cout << "a=" << a << " b=" << b << " a-b=" << a - b << endl;
    Rational c = 3;
    cout << "b=" << b << " c=" << c << " b/c=" << b / c << endl;

    cout << "Тестирования №3 " << endl;
    Rational e(7, 8), f(5, 12);
    cout << "e=" << e << " f=" << f << " e+f=?" << endl;
    cout << "Введите результат g=m/n в формате: m n" << endl;
    Rational g;
    cin >> g;
    if (e + f != g)
        cout << "Неправильно! e+f=" << e + f << endl;
    else
        cout << "Правильно!" << endl;
    return 0;
}
