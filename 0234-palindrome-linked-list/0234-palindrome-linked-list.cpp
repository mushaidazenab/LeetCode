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

   bool isPalindrome(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;

    // this will help us find the middle of list (slow ptr)
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // now we want to reverse the second half
    ListNode *prev = nullptr;
    ListNode *current;
    while (slow != nullptr)
    {
        current = slow->next;
        slow->next = prev;
        prev = slow;
        slow = current;
    }
    // after reversal, slow = nullptr & prev = head of reversed list
    //  now check for palindrome

    ListNode *left = head;
    ListNode *right = prev;

    while (right != nullptr)
    {
        if (left->val !=right->val)
            return false;

        left = left->next;
        right = right->next;
    }
    return true;
}
};