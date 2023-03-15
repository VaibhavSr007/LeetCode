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
    void tot_nodes(TreeNode* root, int& cnt){
        if(root == NULL){
            return ;
        }
        tot_nodes(root->left,cnt);
        cnt++;
        tot_nodes(root->right,cnt);
        
    }
    
    bool solve(TreeNode* root,int idx, int cnt){
        if(root == NULL){
            return true;
        }
        
        if(idx >= cnt){
            return false;
        }
        else{
            bool left = solve(root->left,2*idx+1,cnt);
            bool right = solve(root->right,2*idx+2,cnt);
            
            return left&&right;
        } 
    }
    
    
    bool isCompleteTree(TreeNode* root) {
        
        int cnt = 0;
        tot_nodes(root,cnt);
        cout<<cnt<<" ";
        return solve(root,0,cnt);
        
    }
};