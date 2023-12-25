#include <deque>
#include <iostream>

using namespace std;

bool isValid(string s)
{
    deque<int> dq;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            dq.push_front(')');
        else if (s[i] == '[')
            dq.push_front(']');
        else if (s[i] == '{')
            dq.push_front('}');
        else
        {
            if (dq.empty() || dq.front() != s[i])
                return false;
            dq.pop_front();
        }
    }
    return dq.empty();
}

int main()
{
    string s = "(}";
    cout << isValid(s);
    return 0;
}
