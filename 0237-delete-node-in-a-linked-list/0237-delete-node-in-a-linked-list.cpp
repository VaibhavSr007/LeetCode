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
    void deleteNode(ListNode* node) {
        
//         ListNode *cur = node;  // copying the next elment in cur node
//         ListNode *prev = NULL;  // keeping track of prev node with prev pointer
        
//         while(cur->next!=NULL){
//             cur->val = cur->next->val;   // O(n)  approach
//             prev = cur;
//             cur = cur->next;
//         }
//         prev->next = NULL;  // now making the second last node to point to NULL so the extra node may be removed
        
        
        // *************************** O(1) approach **********************************
        
    //     node->val = node->next->val;  // copying the next node val in the cur node
    //     node->next = node->next->next; // now taking the next node out of list by connecting 
    // }                                   // the present node to next->next node 
        
        
        // if(node->next = NULL){
        //     node = NULL;
        //     return ;       // if node to b deleted was a tail node
        // }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};