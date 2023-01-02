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
    ListNode* deleteDuplicates(ListNode* head) {
        // Set up a pointer to the current node
        ListNode* curr = head;

        // While the current node is not null and has a next node
        while(curr && curr -> next){
            // If the current node has the same value as the next node
            if(curr->val == curr ->next ->val )
                // Set the next node of the current node to be the one after the next node
                // This effectively removes the next node from the list
                curr->next = curr->next->next;
            else
                // Otherwise, move on to the next node
                curr = curr->next;
        } 
        // Return the head of the list
        return head;
    }
};
