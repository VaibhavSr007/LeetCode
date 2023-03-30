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
    ListNode *detectCycle(ListNode *head) {
        
//         if(head == NULL){ // if list is already empty 
//             return NULL;
//         }
        
//         ListNode *slow = head;
//         ListNode *fast = head;
    
//         while(fast != NULL && fast->next != NULL){//gets intersection node if loop present else
//             slow = slow->next;                    // else takes the fast index to NULL
//             fast = fast->next->next;
//             if(slow == fast){
//                 break;
//             }
//         }
//         if(fast == NULL || fast->next == NULL){ // if fast reahes null so no loop
//             return NULL;
//         }
    
//         slow = head; 
    
//         while(slow != fast){ //start new node from head and fast from where it was, move both with 
//             slow = slow->next; // same pace they will intersect at start index
//             fast = fast->next;
//         }
        
        // return fast;
        
        
        // ********** FOR REMOVING LOOP ************
        // while(slow->next != fast){ move slow till it points fast(start of loop)
        //     slow = slow->next;
        // }
        // slow->next = NULL; //so slow reached last node of loop or (prev of start(fast)) n we make it null so loop gets removed
        // return head;
        
        map<ListNode*, int> mp;
        ListNode* cur = head;
        while(cur){
            if(mp.find(cur) != mp.end()){        // map or set approach
                // cout<<cur->val<<" ";
                return cur;
            }
            mp[cur] = cur->val;
            cur = cur->next;
        }
        
        return NULL;
    }
};