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
    void insert(ListNode* ans, ListNode* head){
        while(ans->next && ans->next->val < head->val){
            ans = ans->next;
        }
        head->next = ans->next;
        ans->next = head;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head->next==NULL){ return head;}
        ListNode *ans = new ListNode(INT_MIN);
        
        while(head){
            ListNode *temp = head;
            head = head->next;
            insert(ans,temp);
        }
        return ans->next;
        
        // vector<int> v;
        // while(temp){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(begin(v),end(v));
        // temp = head;
        // int i =0;
        // while(temp){
        //     temp->val = v[i++];
        //     temp = temp->next;
        // }
        // return head;
    }
};