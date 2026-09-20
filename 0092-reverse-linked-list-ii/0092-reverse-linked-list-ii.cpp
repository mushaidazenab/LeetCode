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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head== nullptr || left == right){
            return head;
        }
        ListNode*dummy = new ListNode(0, head); //dummy node helps with easier implementation when left == head - lesser edge cases
        ListNode*prev = dummy;
 
        //we want our prev to be right before left node
        for(int i = 0; i<left - 1; i++){
            prev = prev->next; 
        }
        //after this loop ends, prev stands right bfr left node
        // we set curr == left node

        ListNode*curr = prev->next;
        for(int i = 0; i<right - left; i++){
            ListNode*subs = curr->next;
            curr->next = subs->next;
            subs->next = prev->next;
            prev->next = subs;
        }

        return dummy->next;
    }
};