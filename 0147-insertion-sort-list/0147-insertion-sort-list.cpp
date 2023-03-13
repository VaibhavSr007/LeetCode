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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode *ans = new ListNode(-1);
        ListNode *temp = head;
        ans->next = head;
        
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(begin(v),end(v));
        temp = head;
        int i =0;
        while(temp){
            temp->val = v[i++];
            temp = temp->next;
        }
        return head;
    }
};