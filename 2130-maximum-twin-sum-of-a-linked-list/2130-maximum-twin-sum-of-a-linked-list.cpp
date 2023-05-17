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
    int pairSum(ListNode* head) {
        // ListNode *temp = head;
//         vector<int> v;
//         int ans = 0;
        
//         while(temp){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         int i = 0;
//         int j = v.size()-1;
                                                // brute force
//         while(i<j){
//             int val = v[i] + v[j];
//             ans = max(val,ans);
//             i++;
//             j--;
//         }
        
//         return ans;
        
        ListNode* rev = new ListNode(-1);
        ListNode* cur = rev;
        ListNode* temp = head;
        int cnt = 0, n=0;
        while(temp){
            ListNode* add = new ListNode(temp->val);
            temp = temp->next;
            cur->next = add;
            cur = cur->next;
            cnt++;
        }
        rev = rev->next;
        
        ListNode* forw;
        cur = rev;
        temp = NULL;
        while(forw){
            forw = cur->next;
            cur->next = temp;
            temp = cur;
            cur = forw;
        }
        int ans =INT_MIN;
        while(n != cnt/2){
            int val = temp->val + head->val;
            ans = max(val, ans);
            temp = temp->next;
            head = head->next;
            n++;
        }
        return ans;
    }
};