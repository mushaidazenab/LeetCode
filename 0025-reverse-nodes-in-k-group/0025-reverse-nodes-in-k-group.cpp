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
   ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    int count = 0;
    while (count < k)
    {
        if (temp == nullptr)
        { // not enough nodes exist to form a k group
            // in this case we dont want to reverse so we just return the head
            return head;
        }
        temp = temp->next;
        count++;
    }
    // temp points at k + 1 th node after this loop

    // in standard revverselogic prev = nullptr
    // here we assign it the node returned by our reverseKGroup func
    // this will be the new head after reversal
    ListNode *prev = reverseKGroup(temp, k);
    count = 0;
    ListNode *curr = head;
    while (count < k)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    return prev; // this becomes the updated head after reversal
}
};