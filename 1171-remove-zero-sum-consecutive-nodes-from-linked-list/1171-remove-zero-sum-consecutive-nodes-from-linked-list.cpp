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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
        ListNode* cur = head;
        int sum = 0;
        while(cur){
            sum += cur->val;
            if(sum == 0){
                int sum1 = 0;
                ListNode* temp = head;
                while(temp != cur->next){
                    sum1 += temp->val;
                    mp.erase(sum1);
                    temp = temp->next;
                }
                head = temp;
            }
            
            if(mp.find(sum) != mp.end()){
                // cout<<sum<<":"<<cur->val<<" ";
                
                int sum1 = sum;
                ListNode* temp = mp[sum]->next;
                while(temp != cur){
                    sum1 += temp->val;
                    cout<<sum1<<" ";
                    mp.erase(sum1);
                    temp = temp->next;
                }
                mp[sum]->next = cur->next;
            }
            else{
                mp[sum] = cur;
            }
            
            cur = cur->next;
        }
        
        return head;
    }
};