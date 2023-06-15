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
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){
            return true;
        }
        else if((!root1 && root2) || (root1 && !root2)){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        
       bool l1 = false, r1 = false, l2 = false, r2 = false;
        l1 = flipEquiv(root1->left, root2->left);
        r1 = flipEquiv(root1->right, root2->right);
        l2 = flipEquiv(root1->right, root2->left);
        r2 = flipEquiv(root1->left, root2->right);
        
        return (l1 && r1) || (l2 && r2) ;
    }
};