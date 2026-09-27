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
class Solution
{
public:
   
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int rem = 0;
        ListNode *temp = l1;
        ListNode *l1Prev = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val;
            int total = sum + rem;
            l1->val = total % 10;
            rem = (total > 9) ? 1 : 0;

            l1Prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        // l2 finished
        if (l2 == nullptr)
        {
            while (l1 != nullptr)
            {
                int total = l1->val + rem;
                l1->val = total % 10;
                rem = (total > 9) ? 1 : 0;
                // dry run w this order
                //  l1->val = (sum + rem) % 10;
                //  rem = (sum + rem > 9) ? 1 : 0;
                l1Prev = l1;
                l1 = l1->next;
            }
        }
        // l2 was longer
        if (l1 == nullptr && l2 != nullptr)
        {
            l1Prev->next = l2;
            l1 = l2;
            while (l1 != nullptr && rem > 0)
            {
                int total = l1->val + rem;
                l1->val = total % 10;
                rem = (total > 9) ? 1 : 0;

                l1Prev = l1;
                l1 = l1->next;
            }
        }
        // carry out case
        if (rem == 1)
        {
            // if l1 was empty from the start, update l1Prev carefully
            if (l1Prev != nullptr)
            {
                l1Prev->next = new ListNode(1);
            }
        }
        return temp;
    }
};
