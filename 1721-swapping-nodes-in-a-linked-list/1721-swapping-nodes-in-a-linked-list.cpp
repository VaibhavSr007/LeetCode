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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == NULL){
            return head;
        }
        
        ListNode *temp = head;
        int len = 0;
        
        while(temp!=NULL){  // fining the length of the list
            temp = temp->next;
            len++;
        }
        
        int pos = len - k + 1;
        
        ListNode *cur = head;
        int cnt = 1;
        while(cnt!=k){ //  taking the cur node to the kth posotion from the start
            cur = cur->next;
            cnt++;
        }
        
        temp = head;
        cnt  = 1;
        while(cnt!=pos){ // taking the temp to the kth node from the end 
            temp = temp->next;
            cnt++;
        }
        
        int x; // swaping the values of kth node from end and the start
        x = cur->val;
        cur->val = temp->val;
        temp->val = x;
        
        return head;
    }
};