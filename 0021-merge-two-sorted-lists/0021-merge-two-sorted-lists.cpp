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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL && list2 == NULL){
//             return NULL;
//         }
//         else if(list1 == NULL){
//             return list2;
//         }
//         else if(list2 == NULL){
//             return list1;
//         }
        
//         vector<int> v;
//         ListNode *prev = NULL;
//         ListNode *temp = list1;
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             prev = temp;
//             temp = temp->next;
//         }                                  // vector approch
        
//         temp = list2;
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         sort(v.begin(),v.end());
        
//         prev->next = list2;
        
//         temp = list1;
//         int i = 0;
//         while(temp!=NULL){
//             temp->val = v[i++];
//             temp = temp->next;
//         }
        
//         return list1;
        
// ************************************************************************    
//         if(list1==NULL && list2 == NULL){ return NULL; }
//         else if(list1 == NULL){ return list2; }
//         else if(list2 == NULL){ return list1; }
        
//         if(list1->val>list2->val){
//             return mergeTwoLists(list2,list1);
//         }
        
//         ListNode *cur1 = list1;
//         ListNode *next1 = list1->next;
//         ListNode *cur2 = list2;
//         ListNode *next2 = list2->next;
        
//         if(next1 == NULL){ // only one node in list1 thn next1 is null so it dont go in loop
//             cur1->next = list2;
//             return list1;
//         }

        
//         while(next1 != NULL && cur2!=NULL){
            
//             if(cur2->val >= cur1->val && cur2->val <= next1->val){
//                 cur1->next = cur2;
//                 cur2->next = next1;
//                 cur1 = cur2;
                
//                 cur2 = next2;
//                 if(next2!=NULL){
//                     next2 = next2->next;
//                 }
//             }
//             else{
//                 cur1 = next1;
//                 next1 = next1->next;
//                 if(next1==NULL){ //when list1 is finished but list 2 remians to spmly add list2
//                     cur1->next = cur2;   // at back of list1 and return full 
//                     return list1;
//                 }
//             }
//         }
        
//         return list1;
// ********************************************************************************
        
//         ListNode *l1 = list1;
//         ListNode *l2 = list2;
//         ListNode *ans = new ListNode (-1);
//         ListNode *temp = ans;
        
//         while(l1!=NULL && l2!=NULL){  // both list of same size
//             if(l1->val <= l2->val){
//                 temp->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 temp->next = l2;
//                 l2 = l2->next;
//             }
//             temp = temp->next;
//         }
        
//         if(l1!=NULL){ // if list is larger thn list 2
//             temp->next = l1;
//         }
//         if(l2!=NULL){  // if list 2 is larger than 1
//             temp->next = l2;
//         }
        
//         return ans->next;
        
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* ans = new ListNode(-1);
        ListNode* cur = ans;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
            cur->next = NULL;
        }
        
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        
        return ans->next;
    }
};