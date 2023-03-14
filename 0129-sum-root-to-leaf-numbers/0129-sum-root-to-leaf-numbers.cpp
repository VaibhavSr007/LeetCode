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
//     void solve(TreeNode* root, int sum, int& ans){
//         if(root == NULL){
//             return ;
//         }
//         if(root->left == NULL && root->right == NULL){
//             int x = sum*10 + root->val;
//             ans+= x;
//         }
        
        
//         int dig = root->val;
//         solve(root->left, (sum*10 + dig), ans);
//         solve(root->right, (sum*10 + dig), ans);
//     }
    
    void solve(TreeNode *root, vector<int>& ans, long long op){
        if(!root){
            return ;
        }
        
        if(!root->left && !root->right){
            op = op*10 + root->val;
            ans.push_back(op);
            op = op/10;
            return ;
        }
        
        op = op*10 + root->val;
        if(root->left)
            solve(root->left,ans,op);
        if(root->right)
            solve(root->right,ans,op);
        
    }
    
    int sumNumbers(TreeNode* root) {
//         vector<int> v;
//         int ans = 0;
//         solve(root,0,ans);
        
// //         for(auto i:v){
// //             cout<<i<<" ";
// //             ans += i;
// //         }
        
//         return ans;
        
        vector<int> ans;
        long long op = 0;
        solve(root, ans, op);
        long long res = 0;
        for(auto i:ans){
            cout<<i<<" ";
            res += i;
        }
        return res;
    }
    
    
};