#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
class Complex
{
    template <typename T2>
    friend istream &operator>>(istream &, Complex<T2> &);
    template <typename T2>
    friend ostream &operator<<(ostream &, Complex<T2> &);

private:
    T real;
    T imaginary;

public:
    float norm();
    Complex conjugate();
    Complex(T = 0, T = 0);
    Complex operator+(Complex &);
    Complex operator-(Complex &);
    Complex operator*(Complex &);
    Complex operator/(Complex &);
    bool operator==(Complex<T> &);
    bool operator!=(Complex<T> &);
};
template <typename T>
float Complex<T>::norm()
{
    return sqrt(real * real + imaginary * imaginary);
}
template <typename T>
Complex<T> Complex<T>::conjugate()
{
    return Complex<T>(real, -imaginary);
}
template <typename T>
Complex<T>::Complex(T real, T imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c)
{
    return Complex<T>(real + c.real, imaginary + c.imaginary);
}
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c)
{
    return Complex<T>(real - c.real, imaginary - c.imaginary);
}
template <typename T>
Complex<T> Complex<T>::operator*(Complex<T> &c)
{
    Complex<T> cc;
    cc.real = real * c.real - imaginary * c.imaginary;
    cc.imaginary = real * c.imaginary + imaginary * c.real;
    return cc;
}
template <typename T>
Complex<T> Complex<T>::operator/(Complex<T> &c)
{
    float norm = c.norm();
    Complex<T> cc;
    cc.real = (real * c.real + imaginary * c.imaginary) / (norm * norm);
    cc.imaginary = (real * c.imaginary - imaginary * c.real) / (norm * norm);
    return cc;
}
template <typename T>
bool Complex<T>::operator==(Complex<T> &c)
{
    return real == c.real && imaginary == c.imaginary;
}
template <typename T>
bool Complex<T>::operator!=(Complex<T> &c)
{
    return !(real == c.real && imaginary == c.imaginary);
}
template <typename T>
istream &operator>>(istream &is, Complex<T> &c)
{
    cout << "Please enter real and imaginary: ";
    is >> c.real >> c.imaginary;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, Complex<T> &c)
{
    os << "{Real: " << c.real;
    os << ", Imaginary: " << c.imaginary << "}";
    return os;
}

#endif // COMPLEX_H_INCLUDED