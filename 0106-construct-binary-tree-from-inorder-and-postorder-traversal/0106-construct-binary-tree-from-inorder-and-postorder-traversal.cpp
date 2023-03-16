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
     TreeNode* solve(vector<int> post, vector<int> in, int& idx, int st, int en, map<int,int>& mp){
        if(idx >= in.size() || st > en){
            return  NULL;
        }
        
        int ele = post[idx--];
        int pos = mp[ele];
        
        TreeNode* ans = new TreeNode(ele);
        
        ans->right = solve(post,in,idx,pos+1,en,mp);
        ans->left = solve(post,in,idx,st,pos-1,mp);
        
        return ans;
    }
    
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int,int> mp;
        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
        }
        
        int idx = in.size()-1;
        TreeNode* ans = solve(post,in,idx,0,in.size()-1,mp);
        return ans;
    }
};