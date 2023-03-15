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
    void in(TreeNode* root, bool& v, TreeNode* sub){
        if(!root){
            return ;
        }
        bool chk=false;
        in(root->left,v, sub);
        if(root->val==sub->val){
            chk = solve(root,sub);
        }
        if(chk){
            v = true;
        }
        in(root->right,v, sub);
    }
    
    bool solve(TreeNode* x, TreeNode* y){
        if(!x && !y){
            return true;
        }
        if(!x || !y){
            return false;
        }
        if(x->val != y->val){
            return false;
        }
        
        bool left = solve(x->left,y->left);
        bool right = solve(x->right,y->right);
        return left&&right;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool v = false;
        in(root,v,subRoot);
    
        return v;
    }
};