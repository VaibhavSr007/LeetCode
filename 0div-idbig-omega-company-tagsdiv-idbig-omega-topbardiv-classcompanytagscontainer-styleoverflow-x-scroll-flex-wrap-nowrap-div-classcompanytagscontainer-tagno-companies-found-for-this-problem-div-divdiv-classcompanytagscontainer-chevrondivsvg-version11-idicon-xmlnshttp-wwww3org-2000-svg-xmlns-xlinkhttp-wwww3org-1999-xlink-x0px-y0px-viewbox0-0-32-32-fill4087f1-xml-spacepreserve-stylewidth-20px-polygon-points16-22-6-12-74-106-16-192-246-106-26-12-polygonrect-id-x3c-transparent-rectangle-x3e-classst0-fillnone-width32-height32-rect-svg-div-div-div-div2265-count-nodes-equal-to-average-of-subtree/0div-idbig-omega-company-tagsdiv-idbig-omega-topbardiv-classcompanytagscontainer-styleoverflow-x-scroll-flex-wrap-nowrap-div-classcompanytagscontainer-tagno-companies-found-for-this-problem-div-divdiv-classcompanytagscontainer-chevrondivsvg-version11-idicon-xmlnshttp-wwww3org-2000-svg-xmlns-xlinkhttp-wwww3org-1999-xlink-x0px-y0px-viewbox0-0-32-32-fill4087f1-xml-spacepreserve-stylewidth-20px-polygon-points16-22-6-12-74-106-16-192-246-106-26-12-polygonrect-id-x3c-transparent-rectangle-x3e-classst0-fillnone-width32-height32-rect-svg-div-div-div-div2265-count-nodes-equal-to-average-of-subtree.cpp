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
    int cnt = 0;
    
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> ans;
        ans.first = left.first + right.first + 1;
        int x = (left.second + right.second + root->val);
        int y = (ans.first);
        ans.second = x;
        // cout<<left.first<<"-"<<right.first<<"  "<<left.second<<"-"<<right.second<<endl;
        // cout<<x<<" "<<y<<endl;
        // cout<<ans.second<<" ";
        
        if(x/y == root->val){
            // cout<<root->val<<" ";
            cnt++;
        }
        
        return ans;
    }
    
    
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> ans = solve(root);
        // cout<<endl;
        // cout<<ans.first<<" "<<ans.second<<"=";
        
        return cnt;
    }
};