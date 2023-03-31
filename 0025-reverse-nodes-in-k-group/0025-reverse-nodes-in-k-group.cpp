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

    ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *cur = head;
//         ListNode *temp = head;
//         ListNode *prev = NULL;
//         ListNode *forw = NULL;
        
//         for(int i=0; i<k; i++){//checking if remianing nodes cnt is less thn k if yes rtrn head
//             if(temp == NULL){ // not needed if want to reverse remaining nodes also
//                 return head;
//             }
//             temp = temp->next;
//         }
        
//         int cnt = 0;
        
//         for(int i=0; i<k; i++){ // revring 1 group of k nodes
//             forw = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = forw;
//         }
        
//         if(cur != NULL){//checking if list have elements, than we make recursive call for them
//             head->next =  reverseKGroup(cur,k);
//         }
        
//         return prev;
        
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        ListNode* temp = head;
        for(int i=0; i<k; i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }
        
        for(int i=0; i<k; i++){
            // if(!cur){ break; }  if we want to reverse the letf nodes also 
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        if(cur)
            head->next = reverseKGroup(cur,k);
        
        return prev;
    }
};