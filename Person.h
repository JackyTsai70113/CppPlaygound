#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
class Person
{
    template <typename T2>
    friend istream &operator>>(istream &, Person<T2> &);
    template <typename T2>
    friend ostream &operator<<(ostream &, Person<T2> &);

private:
    string name;
    T height;
    T weight;

public:
    void set_name(string);
    string get_name();
    void set_height(T);
    T get_height();
    void set_weight(T);
    T get_weight();
    Person(string name = "anonymous", T height = 0, T weight = 0);
    ~Person();
    T operator+(Person &p);
};

template <typename T>
void Person<T>::set_name(string n)
{
    name = n;
}

template <typename T>
string Person<T>::get_name()
{
    return name;
}

template <typename T>
void Person<T>::set_height(T n)
{
    height = n;
}

template <typename T>
T Person<T>::get_height()
{
    return height;
}

template <typename T>
void Person<T>::set_weight(T n)
{
    weight = n;
}

template <typename T>
T Person<T>::get_weight()
{
    return weight;
}

template <typename T>
istream &operator>>(istream &is, Person<T> &p)
{
    is >> p.name >> p.height >> p.weight;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, Person<T> &p)
{
    os << "Name: " << p.name << endl;
    os << "Height: " << p.height << endl;
    os << "Weight: " << p.weight << endl;
    return os;
}

template <typename T>
Person<T>::Person(string name, T height, T weight)
{
    this->name = name;
    this->height = height;
    this->weight = weight;
}

template <typename T>
Person<T>::~Person()
{
    cout << "Object was destructed" << endl;
}

template <typename T>
T Person<T>::operator+(Person<T> &p)
{
    return weight + p.weight;
}

#endif // PERSON_H_INCLUDED