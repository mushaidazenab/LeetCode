/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        // first make the list circular
        // and also count total number of nodes
        int count = 1;
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            count++;
            tail = tail->next;
        }
        k = k % count;
        if (k == count)
        {
            return head; // no rotation needed
        }

        // make the list circular
        tail->next = head;

        int stepsToNewTail = count - k - 1;
        ListNode *newTail = head;
        for (int i = 0; i < stepsToNewTail; i++)
        {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};