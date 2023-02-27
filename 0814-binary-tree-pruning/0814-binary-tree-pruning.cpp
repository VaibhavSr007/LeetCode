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
    
    void solve(TreeNode* &root){
        if(!root){
            return ;
        }
        
        solve(root->left);
        solve(root->right);
        
        if(!root->left && !root->right){
            if(root->val==0){
                root = NULL;
            }
            return ;
        }
        
//         bool left = false, right = false;
//         if(root->left && root->left->val==1){
//             left = true;
//         }
//         if(root->right && root->right->val==1){
//             right = true;
//         }

//         if(left || right || root->val==1){
            
//         }
//         else{
//             root = NULL;
//             return ;
//         }
        
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        solve(root);
        return root;
    }
};