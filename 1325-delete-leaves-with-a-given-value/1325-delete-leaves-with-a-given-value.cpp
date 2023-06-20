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
    TreeNode* solve(TreeNode* root, int target){
        if(!root){
            return NULL;
        }
        
        TreeNode* add = new TreeNode(root->val);
        
        add->left = solve(root->left, target);
        add->right = solve(root->right, target);
        
        
        if(!add->left && !add->right && root->val == target){
            return NULL;
        }
        
        return add;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root->left && !root->right && root->val == target){
            return NULL;
        }
        
        return solve(root, target);
    }
};