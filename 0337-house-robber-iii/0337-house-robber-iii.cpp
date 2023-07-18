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
    
    vector<int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        int include = root->val + l[1] + r[1];
        int exclude = max(l[0],l[1])+ max(r[0],r[1]);
        
        return {include, exclude};
    }
    int rob(TreeNode* root) {
         
        vector<int> v = solve(root);
        
        return max(v[1], v[0]);
    }
};