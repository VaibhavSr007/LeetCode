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
    void solve(TreeNode* root, bool isLeft, int &ans, int len){
        if(!root){
            return ;
        }    
        
        ans = max(ans,len);
        
        if(isLeft){
            solve(root->left, true, ans, 1);
            solve(root->right, false, ans, len+1);
        }
        else{
            solve(root->left, true, ans, len+1);
            solve(root->right, false, ans, 1);
        }
    }
    
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root, true, ans, 0);
        return ans;
    }
};