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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         ListNode *l1 = headA;
        
//         while(l1!=NULL){
//             ListNode *l2 = headB;
//             while(l2!=NULL){
//                 if(l1==l2){
//                     return l1;   // brute force
//                 }
//                 l2 = l2->next;
//             }
//             l1 = l1->next;
//         }
//         return NULL;
        
// ***********************************************************
//         map<ListNode*,bool> st;
        
//         ListNode *l1 = headA;
//         while(l1!=NULL){
//             st[l1] = true;           // better set/map approach
//             l1 = l1->next;
//         }
        
//         ListNode *l2 = headB;
//         while(l2!=NULL){
//             if(st[l2] == true){
//                 return l2;
//             }
//             l2 = l2->next;
//         }
        
//         return NULL;
        
// ***************************************************************
//         ListNode *l1 = headA;
//         ListNode *l2 = headB;
        
//         while(l1!=l2){
//             if(l1==NULL){ l1 = headB;}
//             else{ l1 = l1->next; }              // most optimized 
            
//             if(l2==NULL){ l2 = headA;}
//             else{ l2 = l2->next; }
//         }
        
//         return l1;
        
        
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        while(l1!=l2){
            if(!l1){
                l1 = headB;
            }
            else{
                l1 = l1->next;
            }
            
            if(!l2){
                l2 = headA;
            }
            else{
                l2 = l2->next;
            }
            
        }
        // if both doest not have any intersection than ultimately they will intersect at NULL
        
        return l1;
    }
};