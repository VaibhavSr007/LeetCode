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
   
    
    void insertAtTail(ListNode* &tail , int val){
        ListNode *cur = new ListNode(val);
        tail->next = cur;
        tail = tail->next;
    }
    
    ListNode* rev(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* cur = head;
        ListNode* prev = NULL;
         ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next; 
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // ListNode *rev1 = reverse(l1);  // if list is asked to be added from once place
        // ListNode *rev2 = reverse(l2);  // or the rightmost digits
//         ListNode *rev1 = l1;  // when the list is said to be added from the left most place
//         ListNode *rev2 = l2;  // no reverse is needed;
        
//         l1 = rev1;
//         l2 = rev2;
//         int carry = 0;
//         int sum,digit;
//         ListNode *tail = new ListNode(-1);
//         ListNode *head = tail;
        
//         while(rev1!=NULL || rev2!=NULL || carry!=0){  // generic function for all cases
            
//             int val1 = 0;
//             if(rev1!=NULL)
//                 val1 = rev1->val;
            
//             int val2 = 0;
//             if(rev2!=NULL)
//                 val2 = rev2->val;
            
//             sum = val1 + val2 + carry;
//             digit = sum%10;
//             carry = sum/10;
//             insertAtTail(tail,digit);
            
//             if(rev1!=NULL)
//                 rev1 = rev1->next;
            
//             if(rev2!=NULL)
//                 rev2 = rev2->next;
//         }
        
//         while(rev2!=NULL && rev1!=NULL){  // case when both list have same length
//             sum = rev1->val + rev2->val + carry;
//             digit = sum%10;
//             insertAtTail(tail,digit);
//             carry = sum/10;
            
//             rev1 = rev1->next;
//             rev2 = rev2->next;
//         }
        
//         while(rev1!=NULL){  // when list 1 is larger than list 2
//             sum = rev1->val + carry;
//             digit = sum%10;
//             insertAtTail(tail,digit);
//             carry = sum/10;
            
//             rev1 = rev1->next;
//         }
        
//         while(rev2!=NULL){ // when list 2 is larger than list 1
//             sum = rev2->val + carry;
//             digit = sum%10;
//             insertAtTail(tail,digit);
//             carry = sum/10;
            
//             rev2 = rev2->next;
//         }
        
//         while(carry != 0){  // when carry is still remaining after the addtion
//             sum = carry;
//             digit = sum%10;
//             insertAtTail(tail,digit);
//             carry = sum/10;
//         }
        
        // ListNode *ans = reverse(head->next); // if list is asked to be added from once place 
        
        // return head->next;
        
        ListNode* s1 = l1;
        ListNode* s2 = l2;
        ListNode* ans = new ListNode(-1);
         ListNode* cur = ans;
        int car = 0;
        
        while(s1 || s2 || car){
            
            int dig1 = 0;
            if(s1){
                dig1 = s1->val;
            }
            
            int dig2 = 0;
            if(s2){
                dig2 = s2->val;
            }
            
            int dig = dig1 + dig2 + car;
            car = dig/10;
            int val = dig%10;
            
            ListNode* add = new ListNode(val);
            cur->next = add;
            cur = cur->next;
            
            if(s1){
                s1 = s1->next;
            }
            if(s2){
                s2 = s2->next;
            }
        }
        return ans->next;
    }
};