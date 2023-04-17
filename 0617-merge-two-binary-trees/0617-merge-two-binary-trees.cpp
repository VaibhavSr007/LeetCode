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
    void solve( TreeNode* &r1,  TreeNode* &r2){
        
        if(r1 && r2){
            r1->val = r1->val + r2->val;
            
            if(!r1->left && r2->left){
                r1->left = r2->left;
            }
            else if(r1->left && r2->left){
                solve(r1->left,r2->left);
            }
            
            if(!r1->right && r2->right){
                r1->right = r2->right;
            }
            else if(r1->right && r2->right){
                solve(r1->right, r2->right);
            }
        }
        return ;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
         if(!root1){
             return root2;
         }
        if(!root2){
            return root1;
        }
        
        solve(root1, root2);
        return root1;
    }
};