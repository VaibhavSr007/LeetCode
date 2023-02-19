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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool left_to_right = true;
        
        if(root == NULL){
            return ans;
        }
        
        while(!q.empty()){
            int n = q.size();
            vector<int> v(n);
            int idx;
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(left_to_right){
                    idx = i;
                }
                else{
                    idx = n-1-i;
                }
                
                v[idx] = temp->val;
                
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            left_to_right = !left_to_right;
            
            ans.push_back(v);
        }
        
        return ans;
    }
};