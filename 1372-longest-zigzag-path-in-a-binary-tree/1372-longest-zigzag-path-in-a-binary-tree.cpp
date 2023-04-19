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
    
    void solve(TreeNode* root, int cnt,  bool dir, int& ans){
        if(!root){
            return ;
        }       
        
        ans = max(ans, cnt);
        if(dir){
            solve(root->right, ++cnt, false, ans);
            solve(root->left, 1, true, ans);
        }
        else{
            solve(root->left, ++cnt, true, ans);
            solve(root->right, 1, false, ans);
        }
       
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        int cnt  =0;
        bool dir = true;
        solve(root,cnt,dir,ans);
        solve(root,cnt,!dir,ans);
        return ans;
    }
};