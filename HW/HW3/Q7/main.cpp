#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string>& ops)
    {
        int value1;
        int value2;
        int res = 0;
        stack<int>stack;
        
        for(string i:ops)
        {
            if(i == "C")
            {
                stack.pop();
            }
            else if(i == "D")
            {
                stack.push(stack.top()*2);
            }
            else if(i == "+")
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.push(value1);
                stack.push(value1 + value2);
            }
            else
            {
                stack.push(stoi(i));
            }
        }
        while(stack.size() != 0)
        {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};

int main()
{
    vector<string> v = {"5", "2", "C", "D", "+"};
    Solution solution;
    cout << solution.calPoints(v);
}