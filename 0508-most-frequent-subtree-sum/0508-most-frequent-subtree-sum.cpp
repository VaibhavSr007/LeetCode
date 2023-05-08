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
    int sum(TreeNode* root, map<int,int>& mp, int& tot){
        if(!root){
            return 0;
        }
        
        int left = sum(root->left,mp,tot);
        int right = sum(root->right,mp,tot);
        
        tot = left + right + root->val;
        mp[tot]++;
        return tot;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        int t=0;
        sum(root,mp,t);
        int maxi = INT_MIN;
        vector<int> v;
        for(auto i:mp){
            // cout<<i.first<<":"<<i.second<<" ";
            maxi = max(maxi,i.second);
        }
        
        for(auto i:mp){
            if(i.second==maxi){
                v.push_back(i.first);
            }
        }
        return v;
    }
};