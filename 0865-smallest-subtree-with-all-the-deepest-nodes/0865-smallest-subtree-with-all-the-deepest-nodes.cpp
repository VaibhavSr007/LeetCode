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
    
    int count(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int left = count(root->left);
        int right = count(root->right);
        
        return max(right,left) + 1;
    }
    
    TreeNode* solve(TreeNode* root){
        if(!root){ return NULL;}
        
        int l = count(root->left);
        int r = count(root->right);
        
        if(l == r){
            return root;
        }
        if(l < r){
            return solve(root->right);
        }
        else{
            return solve(root->left);
        }
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root){ return NULL;}
        return solve(root);
    }
};