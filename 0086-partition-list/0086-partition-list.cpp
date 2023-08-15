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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans = new ListNode(-1);
        ListNode* copy = ans;
        ListNode* cur = head;
        
        while(cur){
            if(cur->val < x){
                ListNode* add = new ListNode(cur->val); 
                copy->next = add;
                copy  = copy->next;
            }
            cur = cur->next;
        }
        
        cur = head;
        
        while(cur){
            if(cur->val >= x){
                ListNode* add = new ListNode(cur->val); 
                copy->next = add;
                copy  = copy->next;
            }
            cur = cur->next;
        }
        
        
        return ans->next;
    }
};