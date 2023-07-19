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
    void solve(TreeNode* root, int target, int &cnt,  vector<int> v){
        if(!root){
            return ;
        }
        
        v.push_back(root->val);
        long sum = 0;
        for(int i=v.size()-1; i>=0; i--){
            sum += v[i];
            if(sum == target){
                cnt += 1;
            }
        }
        
        solve(root->left, target, cnt, v);
        solve(root->right, target, cnt, v);
        
        v.pop_back();
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        solve(root, targetSum, cnt, {});
        return cnt;
    }
};