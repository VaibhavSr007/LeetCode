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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int targetSum, vector<int> op){
        if(!root){
            return ;
        }    
        
        op.push_back(root->val);
        if(!root->left && !root->right && targetSum - root->val == 0){
            ans.push_back(op);
            return ;
        }
        
        solve(root->left, targetSum - root->val, op);
        solve(root->right, targetSum - root->val, op);
        
        op.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, {});
        return ans;
        
    }
};