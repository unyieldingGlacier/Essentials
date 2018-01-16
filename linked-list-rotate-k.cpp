/* LC 61
 * Given a list, rotate the list to the right by k places, where k is non-negative.
Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* newH = head, *tail = head;    
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        tail->next = head;
        
        //tail is the len-kth element in the new list; so move tail len-k times to find the new head
        k = k%len;  //if len is smaller than k
        for(int i = 0; i < len-k; i++){
            tail = tail->next;
        }
        //tail is now pointing to the last element of the new list
        newH = tail->next;
        tail->next = nullptr;
        return newH;
    }
};

/* Tested.
 * Time: O(n)
 * Spac: O(1)
 */
