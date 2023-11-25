#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
class Course
{
    template <typename T2>
    friend istream &operator>>(istream &, Course<T2> &);
    template <typename T2>
    friend ostream &operator<<(ostream &, Course<T2> &);

private:
    string lecturer;
    int student_number;
    T *grade_list;

public:
    void set_lecturer(string);
    string get_lecturer();
    void set_student_number(int);
    int get_student_number();
    void set_grade_list(T *);
    T *get_grade_list();
    float average();
    Course(string = "anonymous", int = 0);
    ~Course();
    T operator[](int);
};

template <typename T>
void Course<T>::set_lecturer(string lecturer)
{
    this->lecturer = lecturer;
}
template <typename T>
string Course<T>::get_lecturer()
{
    return lecturer;
}
template <typename T>
void Course<T>::set_student_number(int student_number)
{
    this->student_number = student_number;
}
template <typename T>
int Course<T>::get_student_number()
{
    return student_number;
}
template <typename T>
void Course<T>::set_grade_list(T *)
{
    this->grade_list = grade_list;
}
template <typename T>
T *Course<T>::get_grade_list()
{
    return grade_list;
}
template <typename T>
float Course<T>::average()
{
    float sum = 0;
    for (int i = 0; i < student_number; ++i)
        sum += *(grade_list + i);
    return sum / student_number;
}
template <typename T>
Course<T>::Course(string lecturer, int student_number)
{
    this->lecturer = lecturer;
    this->student_number = student_number;
    if (student_number != 0)
        this->grade_list = (T *)calloc(student_number, sizeof(float));
}
template <typename T>
Course<T>::~Course()
{
    cout << "Course finished." << endl;
    free(grade_list);
}
template <typename T>
T Course<T>::operator[](int i)
{
    return *(grade_list + i);
}

template <typename T>
istream &operator>>(istream &is, Course<T> &c)
{
    cout << "lecturer: ";
    is >> c.lecturer;
    cout << "student_number: ";
    is >> c.student_number;
    cout << "grade_list: ";
    for (int i = 0; i < c.student_number; ++i)
    {
        is >> *(c.grade_list + i);
    }
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, Course<T> &c)
{
    os << "lecturer: " << c.lecturer << endl;
    os << "student_number: " << c.student_number << endl;
    os << "grade_list: ";
    for (int i = 0; i < c.student_number; ++i)
        os << *(c.grade_list + i) << " ";
    os << endl;
    return os;
}

#endif // COURSE_H_INCLUDED