#include "Course.h"
#include <iostream>

int main()
{
    int grade_list[] = {1, 2, 3, 4, 5};
    Course<float> c("123", 5);
    cin >> c;
    cout << c;
    cout << c[2] << endl;
    return 0;
}