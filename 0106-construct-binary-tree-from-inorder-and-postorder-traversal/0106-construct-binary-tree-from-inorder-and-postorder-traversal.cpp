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
    TreeNode* solve(int &idx, int st, int en, map<int,int> & mp, vector<int>& pos, vector<int>& in){
        
        if(idx < 0 || st > en){
            return NULL;
        }
        
        int element = pos[idx--]; 
        int position = mp[element];
        
        TreeNode* add = new TreeNode(element);
        
        add->right = solve(idx, position+1, en, mp, pos , in);
        add->left = solve(idx, st, position-1, mp, pos , in);
        
        return add;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int idx = postorder.size()-1, st = 0, en = postorder.size()-1;
        return solve(idx, st, en, mp, postorder, inorder);
    }
    
};