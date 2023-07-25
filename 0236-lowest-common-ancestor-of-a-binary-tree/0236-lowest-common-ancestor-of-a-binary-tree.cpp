/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode* tar, vector<TreeNode*> &ans, vector<TreeNode*> &v){
        if(!root){
            return ;
        }
        
        if(root == tar){
            v.push_back(root);
            ans = v;
            return ;
        }
        
        v.push_back(root);
        solve(root->left, tar, ans, v);
        solve(root->right, tar, ans, v);
        v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans1, ans2, v1, v2;
        solve(root, p, ans1, v1);
        solve(root, q, ans2, v2);
        
        int x = min(ans1.size(), ans2.size());
        TreeNode* ans = NULL;
        for(int i=0; i<x; i++){
            if(ans1[i]->val != ans2[i]->val){
                return ans;
            }
            ans = ans1[i];
        }
        
        return ans;
    }
};