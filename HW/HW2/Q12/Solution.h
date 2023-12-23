// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr) return head;

        int size = 1;
        ListNode *res = head, *tail = head;

        while (tail->next)
        {
            tail = tail->next;
            size++;
        }
        tail->next = head;

        if (k %= size)
        {
            for (auto i = 0; i < size - k; i++)
                tail = tail->next;
        }
        res = tail->next;
        tail->next = nullptr;
        return res;
    }
};