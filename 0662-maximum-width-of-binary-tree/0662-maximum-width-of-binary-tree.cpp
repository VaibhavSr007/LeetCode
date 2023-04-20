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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){ return 0;}
        
        queue<pair<TreeNode*, long long>> q;
        long long idx = 0;
        int ans = 0;
        q.push({root,idx});
        
        while(!q.empty()){    
            int n =q.size();
            int left = q.front().second;
            int right = q.back().second;
            ans = max(ans, right-left+1);
            
            for(int i=0; i<n; i++){
                auto temp = q.front().first;
                long long index = q.front().second - right;
                q.pop();
                if(temp->left){
                    q.push({temp->left, 2*index+1});
                }
                if(temp->right){
                    q.push({temp->right, 2*index+2});
                }
            }
        }
        return ans;
    }
};