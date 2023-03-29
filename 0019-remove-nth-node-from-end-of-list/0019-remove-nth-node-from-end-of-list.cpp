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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int len = 0;
//         ListNode* temp = head;
//         while(temp != NULL){  // getting size
//             temp = temp->next;
//             len++;
//         }
        
//         cout<<len<<" ";
//         int pos = len - n;
//         int cnt = 0;
//         ListNode* cur = head;
//         ListNode* prev = NULL;
        
//         if(pos == 0){ // removing 1st node if len-pos == 0 (edge case)
//             head = head->next;
//             return head;   
//         }
        
//         for(int i=0; i<pos; i++){ // taking our cur node to node which is to be deleted
//             prev = cur;
//             cur = cur->next;
//         }
        
//         if(prev != NULL){ //  removing the req node (if prev is null it can not have next)
//             prev->next = cur->next;   // for this step
//             cur->next = NULL;
//         }
        
//         return head;
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        int cnt = 0;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        
        int len = cnt - n;
        if(len==0){
            return head->next;
        }
        cnt = 0;
        cur = head;
        while(cnt < len){
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        
        prev->next = cur->next;
        return head;
    }
};