#include <iostream>
#include <vector>

using namespace std;

class Disjoint_Set
{
private:
    // 併查集的資料個數
    int counts;
    // 值小於零代表他是根節點，絕對值代表集合個數。值大於等於零代表父節點
    vector<int> set;

public:
    Disjoint_Set(int = 10);
    // 回傳根節點的編號
    int Find_Set(int);
    // 融合兩個 Set
    void Merge_Set(int, int);
};

Disjoint_Set::Disjoint_Set(int number)
{
    counts = number;
    set.resize(counts);

    for (int i = 0; i < set.size(); i++)
    {
        set[i] = -1;
    }
}

int Disjoint_Set::Find_Set(int target)
{
    int root = target;
    while (set[root] >= 0)
    {
        root = set[root];
    }
    while (target != root)
    {
        int predecessor = set[target];
        set[target] = root;
        target = predecessor;
    }
    return root;
}

void Disjoint_Set::Merge_Set(int u, int v)
{
    int u_root = Find_Set(u);
    int v_root = Find_Set(v);
    if (set[u_root] < set[v_root])
    {
        set[u_root] += set[v_root];
        set[v_root] = u_root;
    }
    else
    {
        set[v_root] += set[u_root];
        set[u_root] = v_root;
    }
}

int main()
{
    Disjoint_Set data(5);
    data.Merge_Set(0, 1);
    data.Merge_Set(1, 2);
    for (int i = 0; i < 5; i++)
    {
        cout << "Set of data: " << i << " is " << data.Find_Set(i) << endl;
    }

    data.Merge_Set(3, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << "Set of data: " << i << " is " << data.Find_Set(i) << endl;
    }
    return 0;
}