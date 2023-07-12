/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> mp;
    void parent(TreeNode* root, TreeNode* &target, int start){
        if(!root){
            return ;
        }
        
        if(root->val == start){
            target = root;
        }
        
        if(root->left){
            mp[root->left] = root;
            parent(root->left, target, start);
        }
        if(root->right){
            mp[root->right] = root;
            parent(root->right, target, start);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target = NULL;
        set<TreeNode*> vis;
        queue<TreeNode*> q;
        int cnt = 0;
        
        parent(root, target, start);
        
        q.push(target);
        vis.insert(target);
        while(!q.empty()){
            int n = q.size();
            cnt++;
            
            for(int i=0; i<n; i++){
                auto temp = q.front();
                q.pop();
                // cout<<temp->val<<" ";
                if((vis.find(mp[temp]) == vis.end()) && mp[temp] != NULL){
                    q.push(mp[temp]);
                    vis.insert(mp[temp]);
                } 
                
                if( temp->left && (vis.find(temp->left) == vis.end())){
                    q.push(temp->left);
                    vis.insert(temp->left);
                }
                
                if(temp->right && (vis.find(temp->right) == vis.end())){
                    q.push(temp->right);
                    vis.insert(temp->right);
                }
            }
            cout<<endl;
        }
        
        return cnt-1;
        
    }
};