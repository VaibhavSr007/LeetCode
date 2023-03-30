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
    
    bool isPalindrome(ListNode* head) {
//         string s;
//         ListNode *temp = head;
//         while(temp!=NULL){
//             s.push_back(temp->val+'0');
//             temp = temp->next;
//         }
//         string rev = s;                     approach using string
//         reverse(rev.begin(),rev.end());
        
//         if(rev == s){
//             return true;
//         }
//         return false;
        
//         ListNode *cur = head;
//         ListNode *forw = NULL;
//         ListNode *slow = head;
//         ListNode *fast = head;
        
//         if(head==NULL || head->next==NULL){
//             return true;
//         }
        
//         while(fast != NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         ListNode *mid = slow->next;
//         slow->next = NULL;
        
//         while(mid!=NULL){
//             forw = mid->next;
//             mid->next = slow;
//             slow = mid;
//             mid = forw;
//         }
        
//         while(head!=slow && slow!=NULL){
//             if(head->val != slow->val){
//                 return false;
//             }
//             slow = slow->next;
//             head = head->next;
//         }
        
//         return true;

    // ***************************************************************************
        // ListNode* prev = NULL;
//         ListNode* next = NULL;
//         ListNode* cur = head;
//         ListNode* ans = new ListNode(-1);
//         ListNode* copy = ans;
        
//         while(cur){
//             ListNode* add = new ListNode(cur->val);  reverse linked list and compare 
//             copy->next = add;
//             copy = copy->next;
//             cur = cur->next;
//         }
        
//         cur = head;
//         ans = ans->next;
//         copy = ans;
//         while(copy){
//             next = copy->next;
//             copy->next = prev;
//             prev = copy;
//             copy = next;
//         }
        
//         ans = prev;
//         while(ans){
//             if(ans->val != head->val){
//                 return false;
//             }
//             ans = ans->next;
//             head = head->next;
//         }
        
//         return true; 
        
        if(!head || !head->next){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev1 = NULL;
        ListNode* next = NULL;
        
        while(fast && fast->next){
            fast = fast->next->next;
            prev1 = slow;
            slow = slow->next;
        }
        
        ListNode* prev = NULL;
        while(slow){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        prev1->next = prev;
        ListNode* mid = prev;
        while(head != mid){
            if(head->val != prev->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }   
};