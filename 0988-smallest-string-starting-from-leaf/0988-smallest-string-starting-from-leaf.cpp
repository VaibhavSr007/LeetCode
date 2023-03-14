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
    void solve(TreeNode *root, vector<string>& ans, string op){
        if(!root){
            return ;
        }
        
        if(!root->left && !root->right){
            op.push_back(char(root->val+'a'));
            ans.push_back(op);
            op.pop_back();
            return ;
        }
        
        op.push_back(char(root->val+'a'));
        if(root->left)
            solve(root->left,ans,op);
        if(root->right)
            solve(root->right,ans,op);
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string op = "";
        solve(root, ans, op);
        for(int i=0; i<ans.size(); i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};