/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *getKth(ListNode *curr, int k)
{
    while (curr != nullptr && k > 0)
    {
        curr = curr->next;
        k--;
    }
    return curr; // if there are not enough elements to form a k gruop hen returns nullptr
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *groupPrev = dummy;

    while (true)
    {
        ListNode *kth = getKth(groupPrev, k);
        if (kth == nullptr)
        {
            break; // in case there are not enough nodes to form k group
        }

        ListNode *groupNext = kth->next;
        ListNode *prev = groupNext;
        ListNode *curr = groupPrev->next; //head, since prev = dummy

        while (curr != groupNext)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // relinking groups
        ListNode *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}
};