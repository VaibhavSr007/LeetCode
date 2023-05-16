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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *cur = head;
//         ListNode *dum = new ListNode();
//         ListNode *temp = dum;
        
//         while(cur!=NULL && cur->next!=NULL){
//             temp->next = cur->next;
//             cur->next = temp->next->next;
//             temp->next->next = cur;
//             temp = cur;
//             cur= cur->next;
//         }
        
        ListNode *temp = cur->next;
        ListNode *ans = new ListNode(-1);
        ListNode* prev = ans;
        
        while(cur && cur->next){
            cur->next = cur->next->next;
            temp->next = cur;
            prev->next = temp;
            prev = cur;
            cur = cur->next;
            if(cur)
                temp = cur->next;
            
        }
        
        return ans->next;
        // return dum->next;
        
        
        
//         vector<int> v;
//         ListNode *temp = head;           // not optimised one
        
//         while(temp != NULL){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         for(int i=0; i<v.size()-1; i++){
//             if(i%2==0){
//                 swap(v[i],v[i+1]);
//             }
//         }
        
//         temp =  head;
//         int i = 0;
//         while(temp != NULL){
//             temp->val = v[i++];
//             temp = temp->next;
//         }
        
//         return head;
        
    }
};