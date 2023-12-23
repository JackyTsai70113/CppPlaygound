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
    // https://leetcode.com/problems/remove-linked-list-elements
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;
        while (head != nullptr && head->val == val)
            head = head->next;

        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};