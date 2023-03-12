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
    TreeNode* solve(int st, int en, vector<int> v){
        if(st>en){
            return NULL;
        }
        
        int mid = (st+en)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(st,mid-1,v);
        root->right = solve(mid+1,en,v);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(0,nums.size()-1,nums);
    }
};