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
{ // what ive thought of doing is:
  // we have to reverse the list only from left to right and the remaining list should remain the same, right
  // so essentially what were trying to do is:
  // make (left - 1)th node point to right node
  // make the left node point to (right + 1)th node
  // then from left till right node, reverse the list (using simple pointers like we did already)

    // first we check if the list is empty, if so return (nth to reverse)
    if (head == nullptr)
        return head;

    // we're going to traverse the list to find: left - 1 th node, left node, and right + 1 th node and
    // store them so that we can modify them later

    ListNode *rightPlusOnethNode = head;
    ListNode *leftMinusOnethNode;
    ListNode *leftNode;

    // finding right + 1th node (since later, we want to leftNode to point to right + 1 th node)
    for (int j = 0; j < right; j++)
        rightPlusOnethNode = rightPlusOnethNode->next;

    // we need to consider the cases when left = 1, we wont have left - 1 th node then, so:
    if (left == 1)
        leftNode = head;

    else
    {
        leftMinusOnethNode = head;
        for (int i = 0; i < left - 2; i++)
            leftMinusOnethNode = leftMinusOnethNode->next;
        leftNode = leftMinusOnethNode->next;
    }

    // pointers to reverse
    ListNode *current = leftNode->next; // initially, lies one step ahead of left node
    ListNode *prev = leftNode;          // initially, lies on leftnode (one step behind current)
    ListNode *next;                     // will stay one step ahead of current
    leftNode->next = rightPlusOnethNode;

    for (int k = left; k <= right - 1; k++)
    {
        // simple reverse algorithm
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // notice that after this loop, prev basically points to right node
    // this is exactly what we wanted (left - 1 th node to point to right node)
    if (left == 1)
        head = prev;
    else
        leftMinusOnethNode->next = prev;

    return head;
}
};