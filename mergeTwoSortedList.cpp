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
    // This function takes in two linked lists (list1 and list2) and returns their merged version
    // in a sorted manner.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If either of the lists is empty, return the other list
        if(list1==NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        // Create pointers to keep track of the head and tail of the merged list
        ListNode* head, *tail;
       
        // If the first element of list1 is smaller than the first element of list2,
        // set the head of the merged list to be the first element of list1 and move list1's pointer
        // to the next element. Otherwise, set the head of the merged list to be the first element
        // of list2 and move list2's pointer to the next element.
        list1 -> val < list2 -> val ? (head = list1, list1 = list1 ->next):(head = list2, list2 =list2->next);
        tail = head; // Set the tail to be the same as the head initially


        // Iterate through both lists until one of them becomes empty
        while(list1!=NULL && list2 != NULL){
            // If the current element of list1 is larger than the current element of list2,
            // add the current element of list2 to the merged list and move list2's pointer to the next element.
            // Otherwise, add the current element of list1 to the merged list and move list1's pointer to the next element.
            if(list1->val > list2->val){
                tail->next = list2;
                list2 = list2->next;
            }
            else{
                tail->next = list1;
                list1 = list1->next;
            }
            // Move the tail pointer to the next element in the merged list
            tail = tail->next;
        }
        // If list1 has become empty, add the remaining elements of list2 to the merged list.
        // Otherwise, add the remaining elements of list1 to the merged list.
        if(list1 == NULL){
            tail ->next = list2;
        }
        else{
            tail ->next = list1;
        }
       // Return the head of the merged list
       return head; 
    }
};
