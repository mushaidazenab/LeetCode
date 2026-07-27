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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr || left == right)
        return head;

    ListNode *leftMinusOnethNode = nullptr;
    ListNode *current = head;

    for (int i = 1; i < left; i++)
    {
        leftMinusOnethNode = current;
        current = current->next;
    }

    ListNode *leftNode = current;

    ListNode *rightPlusOnethNode = current;
    for (int i = left; i <= right; i++)
        rightPlusOnethNode = rightPlusOnethNode->next;

    current = leftNode->next;
    leftNode->next = rightPlusOnethNode;

    ListNode *prev = leftNode;

    for (int i = left + 1; i <= right; i++)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (leftMinusOnethNode != nullptr)
        leftMinusOnethNode->next = prev;
    else
        head = prev;

    return head;
}
};