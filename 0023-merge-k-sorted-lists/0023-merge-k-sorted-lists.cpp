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
    
    void insertAtTail(ListNode* &tail, int val){
        ListNode *temp = new ListNode(val);
        tail->next = temp;
        tail = tail->next;
    }
    
    ListNode* merge2List(ListNode* head1, ListNode* head2){
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        ListNode *mer = new ListNode(-1);
        ListNode *tail = mer;
        
        while(temp1 != NULL && temp2 !=NULL){
            if(temp1->val < temp2->val){
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else{
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }
        
        if(temp1){
            tail->next = temp1;
        }
        if(temp2){
            tail->next = temp2;
        }
        
        return mer->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//         if(lists.size()==0){  // brute force approach
//             return NULL;
//         }
//         if(lists.size()==1){
//             return lists[0];
//         }
//         vector<int> v;
//         for(auto i:lists){
//             ListNode *temp = i;
//             while(temp!=NULL){
//                 v.push_back(temp->val);
//                 temp = temp->next;
//             }
//         }
        
//         sort(v.begin(),v.end());
        
//         ListNode *ans = new ListNode(-1);
//         ListNode *tail = ans;
//         for(int i=0; i<v.size(); i++){
//             insertAtTail(tail,v[i]);
//         }
        
//         return ans->next;
        
        // **************************************************************************
        // optimized approach; 
        
        ListNode *ans  = new ListNode(INT_MIN);
        ListNode *tail = ans;
        for(auto i:lists){
            if(i != NULL)
                tail = merge2List(i,tail);
        }
        return tail->next;
    }
};