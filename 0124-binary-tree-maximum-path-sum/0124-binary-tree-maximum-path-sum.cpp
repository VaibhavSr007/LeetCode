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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        ans = max(ans, left + right + root->val);
        
        int res = max(max(right, left) + root->val, 0);
        return res;  
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};