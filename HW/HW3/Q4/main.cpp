#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cout << "Please enter str: ";
    string s;
    cin >> s;

    stack<char> stack;
    for (int i = 0; i < s.size(); ++i)
    {
        stack.push(s[i]);
    }

    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
    return 0;
}
