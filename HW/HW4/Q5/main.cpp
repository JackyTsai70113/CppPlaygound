#include <algorithm>
#include <list>
#include <fstream>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
    list<int> l{1, 2, 3};
    clock_t s, f;
    int from, to;
    unordered_map<int, list<int>::iterator> map;
    map[1] = find(l.begin(), l.end(), 1);
    map[2] = find(l.begin(), l.end(), 2);
    map[3] = find(l.begin(), l.end(), 3);

    ifstream file("Homework_2_1_2.txt");
    if (file)
    {
        s = clock();
        while (file >> from >> to)
        {
            map[to] = l.insert(map[from], to);
        }
        f = clock();
        cout << "(After use map) Time consumption for insert by value: " << (f - s) / (double)CLOCKS_PER_SEC << " seconds" << endl;
    }

    return 0;
}