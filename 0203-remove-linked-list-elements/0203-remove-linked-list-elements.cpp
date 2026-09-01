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
    ListNode *removeElements(ListNode *head, int v)

    {
        ListNode *temp = head;
        // if (head == nullptr) - this part is not needed, already being handled
        //    return head;
        while (head != nullptr && head->val == v)
        {
            head = temp->next;
            delete temp;
            temp = head;
        }
        ListNode *prev = temp;
        while (temp != nullptr)
        {

            if (temp->val == v)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};