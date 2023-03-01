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
    
    ListNode* rev(ListNode* &head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> v;
//         vector<int> ans;
//         ListNode *temp = head;
//         if(head->next==NULL){
//             return {0};
//         }
        
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         for(int i=0; i<v.size()-1; i++){
//             for(int j=i+1; j<v.size(); j++){
//                 if(v[j]>v[i]){
//                     ans.push_back(v[j]);
//                     break;
//                 }
//             }
//             if(ans.size()<i+1){
//                 ans.push_back(0);
//             }
//         }
        
//         ans.push_back(0);
        
//         return ans;
        
        vector<int> ans;
        stack<int> st;
        st.push(0);
        ListNode* cur = rev(head);
        ListNode* temp = cur;
        
        while(temp){
            while(st.top()!=0 && st.top()<=temp->val){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(temp->val);
            temp = temp->next;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};