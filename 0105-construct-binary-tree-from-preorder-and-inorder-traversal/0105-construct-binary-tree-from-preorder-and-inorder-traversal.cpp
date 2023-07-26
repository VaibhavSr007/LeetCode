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
    TreeNode* solve(int &idx, int st, int en, map<int,int> & mp, vector<int>& pre, vector<int>& in){
        
        if(idx >= pre.size() || st > en){
            return NULL;
        }
        
        int element = pre[idx++]; 
        int position = mp[element];
        
        TreeNode* add = new TreeNode(element);
        
        add->left = solve(idx, st, position-1, mp, pre , in);
        add->right = solve(idx, position+1, en, mp, pre , in);
        
        return add;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mp;
        
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int idx = 0, st = 0, en = preorder.size()-1;
        return solve(idx, st, en, mp, preorder, inorder);
    }
};