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
    bool post(TreeNode* x, TreeNode* y){
        if(!x && !y){
            return true;
        }
        else if(!x || !y){
            return false;
        }
        else if(x->val != y->val){
            return false;
        }
        
        return post(x->left,y->right) && post(y->left,x->right);
    }
    
    
    bool isSymmetric(TreeNode* root) {
       if(!root->left && !root->right){
           return true;
       }
       else if(!root->left || !root->right){
            return false;
        }
        
        return post(root->left,root->right);
    }
    
};