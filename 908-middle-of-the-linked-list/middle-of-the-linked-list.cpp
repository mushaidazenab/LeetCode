class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while ((fastPtr != nullptr) && (fastPtr->next != nullptr))
        {
            fastPtr = fastPtr->next;
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};