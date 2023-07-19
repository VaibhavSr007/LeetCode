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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        
        
        ListNode* cur = head;
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        vector<int> v;
        
        while(cur){
            if(cur->val == 0){
                ListNode* add = new ListNode(sum);
                res->next = add;
                res = res->next;
                sum = 0;
            }
            else{
                sum += cur->val;
            }
            cur = cur->next;
        }
        
        return ans->next->next;
    }
};