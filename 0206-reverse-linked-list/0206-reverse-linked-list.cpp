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
//     void solve(ListNode* &cur, ListNode* &prev, ListNode* &forw){
//         if(cur == NULL){
//             return ;
//         }
        
//         forw = cur->next;   // recursive soln
//         cur->next = prev;      
//         prev = cur;
//         cur = forw;
//         solve(cur,prev,forw);
//     }
    
    ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode *cur = head;
//         ListNode *prev = NULL;
//         ListNode *forw = NULL;
        
// //         while(cur != NULL){
// //             forw = cur->next;
// //             cur->next = prev;    Iterative soln
// //             prev = cur;
// //             cur = forw;
// //         }
        
//         solve(cur,prev,forw);
//         return prev;
        
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};