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
    bool hasCycle(ListNode *head) {
//         ListNode *fast = head;
//         ListNode *slow = head;         //  best soln  o(n)   o(n)
        
//         while(fast != NULL && fast->next != NULL){
//             fast = fast->next->next;
//             slow = slow->next;
            
//             if(slow == fast){
//                 return true;
//             }   
//         }
//         return false;
        
//         int cnt = 0;
//         while(head!=NULL){
//             head = head->next;
//             cnt++;             // o(n)  o(1) soln with no extra space
            
//             if(cnt>10000){
//                 return true;
//             }
//         }
//         return false;
        
        map<ListNode*, int> mp;
        ListNode* cur = head;
        while(cur){
            if(mp.find(cur) != mp.end()){
                cout<<cur->val<<" ";
                return true;
            }
            mp[cur] = cur->val;
            cur = cur->next;
        }
        
        return false;
    }
};