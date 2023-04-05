/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &tail, int val){
        Node *add = new Node(val);
        tail->next = add;
        tail = tail->next;
    }
    
    Node* copyRandomList(Node* head) {
        
//         Node *temp = head;
//         Node *copy = new Node(-1); // creation of copy list with dummy node
//         Node *cur = copy;  // tail pointer for the copy list
        
//         while(temp!=NULL){ // just copy main the list with next pointer to copy list
//             insertAtTail(cur,temp->val); 
//             temp = temp->next;
//         }
//         copy = copy->next; // moving next dummy node for reaching main copy list
        
        
//         map<Node*,Node*> mp;
//         temp = head;  // reseting the head in main list and cur in copy list
//         cur = copy;
//         while(temp!=NULL && cur!=NULL){ // mapping of main list nodes with corresponding 
//             mp[temp] = cur;            // copy list's node
//             temp = temp->next;
//             cur = cur->next;
//         }

        
//         temp = head; // reseting the head in main list and cur in copy list
//         cur = copy;
//         while(cur!=NULL && temp!=NULL){ // making the copy list's random point to req nodes, 
//             cur->random = mp[temp->random]; // with the help of map 
//             cur = cur->next;
//             temp = temp->next;
//         }
     
//         return copy;
//         *****************************************************************************************
//         Node *copy = new Node (-1);
//         Node *tail = copy;
//         Node *temp = head;
//         while(temp!=NULL){
//             insertAtTail(tail,temp->val);
//             temp = temp->next;
//         }
//         copy = copy->next;
        
        
//         temp = head;
//         tail = copy;
//         while(temp!=NULL && tail!=NULL){//this will create zigzag connection between both lists
//             Node* next = temp->next;
//             temp->next = tail;
//             temp = next;
            
//             next = tail->next;
//             tail->next = temp;
//             tail = next;
//         }
        
//         temp = head;
//         tail = copy;
//         while(temp!=NULL && temp->next!=NULL){ // setting random pointers in the copy list
            
//             if(temp->random!=NULL){
//                 temp->next->random = temp->random->next;
//             }
//             else{
//                 temp->next->random = NULL;
//             }
//             temp = temp->next->next;
            
//         }
        
//         temp = head;
//         tail = copy;
//         while(temp!=NULL && tail!=NULL){ // unlinking the copy list and original list
//             temp->next = tail->next;
//             temp = temp->next;
            
//             if(temp!=NULL)
//                 tail->next = temp->next;
//             tail = tail->next;
//         }
        
//         return copy;
        
        
        Node* copy = new Node(-1);
        Node* cur = copy;
        Node* temp = head;
        while(temp){
            Node* add = new Node(temp->val);
            cur->next = add;
            cur = cur->next;
            temp = temp->next;
        }
        
        map<Node*, Node*> mp;
        cur = copy->next;
        temp = head;
        while(temp){
            mp[temp] = cur;
            mp[cur] = temp;
            temp = temp->next;
            cur = cur->next;
        }
        
        cur = copy->next;
        while(cur){
            cur->random = mp[mp[cur]->random];
            cur = cur->next;
        }
        
        return copy->next;
    }
};