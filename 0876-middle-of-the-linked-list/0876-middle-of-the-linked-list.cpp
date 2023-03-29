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
    ListNode* middleNode(ListNode* head) {
//         if(head->next==NULL){ // edge case for if it has only 1 ele
//             return head;
//         }
        
//         ListNode *temp = head;
//         int cnt = 0;
        
//         while(temp != NULL){  // for getting length of list
//             cnt++;
//             temp = temp->next;  
//         }
//         // cout<<temp->val<<" ";
//         cout<<cnt<<endl;
        
//         int n =cnt/2;
//         int count = 0;
//         while(count != n){ // fot gettin to middle idx
//             head = head->next;
//             count++;
//         }
//         return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // while(fast!=NULL && fast->next != NULL){  // slow - fast pointer approach when fast                                finishes slow reaches middle bcz fast moves at double sppe of slow
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // return slow;
        
        // while(fast && fast->next){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // return slow;
        
        int cnt = 0;
        while(fast){
            fast = fast->next;
            cnt++;
        }
        cnt /=2;
        while(cnt != 0){
            slow = slow->next;
            cnt--;
        }
        return slow;
    }
};