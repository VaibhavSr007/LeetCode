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
    void inorder(TreeNode* root, map<int,int>& mp){
        if(!root){
            return ;
        }
        
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        inorder(root,mp);
        int maxi = INT_MIN;
        for(auto i:mp){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};