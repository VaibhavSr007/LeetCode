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
        if(head == NULL || head->next==NULL){
            return head;
        }
        
        // ListNode *cur = head;
        // ListNode *prev = NULL;
        // ListNode *forw = NULL;
        // while(cur!=NULL && cur->next!=NULL){
        //     if(cur->val == cur->next->val){
        //         while(cur->next!=NULL && cur->val == cur->next->val){
        //             cur = cur->next;
        //         }
        //         forw = cur->next;
        //         if(prev == NULL){ // if starting of LL itself have duplicates
        //             head = forw;
        //             cur->next = NULL;
        //         }
        //         else{
        //             prev->next = cur->next;    
        //         }
        //         cur = forw;
        //     }
        //     else{
        //         prev = cur;
        //         cur = cur->next;
        //     }
        // }
        // return head;
        
//         ListNode *cur = head;
//         ListNode *prev = NULL;
//         ListNode *forw = NULL;
//         while(cur!=NULL && cur->next!=NULL){
            
//             if(cur->val == cur->next->val){
//                 while(cur->next!=NULL && cur->val == cur->next->val){
//                     cur = cur->next;
//                 }
//                 if(prev == NULL){ // if starting of LL itself have duplicates
//                     head = cur->next;
//                 }
//                 else{
//                     prev->next = cur->next;    
//                 }
//                 cur = cur->next;
//             }
            
//             else{
//                 prev = cur;
//                 cur = cur->next;
//             }
//         }
        
//         return head;
        
        if(!head || !head->next){
            return head;
        }
        
        ListNode* cur = head;
        ListNode* prev = new ListNode(-1);
        ListNode* ans = prev;
        prev->next = head;
        
        while(cur && cur->next){
            
            if(cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val){
                    cur->next = cur->next->next;
                }
                cur = cur->next;
                prev->next = cur;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return ans->next;
    }
};