class Solution {
public:
    ListNode *getKth(ListNode *curr, int k)
    {
        int i = 0;
        while (curr != nullptr && i < k)
        {
            curr = curr->next;
            i++;
        }
        return curr;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k <= 1) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head->prev = dummy; // Set initial prev for dummy connection

        ListNode *groupPrev = dummy;

        while (true)
        {
            ListNode *kth = getKth(groupPrev, k);
            if (kth == nullptr)
            {
                break; // Not enough nodes left to form a k-group
            }

            ListNode *groupNext = kth->next;
            ListNode *curr = groupPrev->next;
            ListNode *oldGroupHead = curr; // Will become group tail after reversal

            // 1. Reverse the inner group pointers (swap next and prev for each node)
            ListNode *prevNode = groupNext;
            while (curr != groupNext)
            {
                ListNode *tempNext = curr->next;
                curr->next = prevNode;
                curr->prev = tempNext; // Swap prev direction
                prevNode = curr;
                curr = tempNext;
            }

            // 2. Fix external links around the reversed group
            groupPrev->next = kth;
            kth->prev = groupPrev;

            if (groupNext != nullptr)
            {
                groupNext->prev = oldGroupHead;
            }

            // 3. Move groupPrev to the end of the reversed group
            groupPrev = oldGroupHead;
        }

        ListNode *newHead = dummy->next;
        if (newHead != nullptr)
        {
            newHead->prev = nullptr; // Detach dummy reference
        }
        delete dummy;
        return newHead;
    }
};
