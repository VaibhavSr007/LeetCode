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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int res = 0;
            for(int i=0; i<n; i++){
                auto temp = q.front();
                res += temp->val;
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            sum.push_back(res);
        }
        
        // here we syart
        root->val = 0;
        q.push(root);
        int lev = 0;
        while(!q.empty()){
            int n = q.size();
            lev++;
            for(int i=0; i<n; i++){
                auto temp = q.front();
                q.pop();
                int res = 0;
                if(temp->left){
                    res += temp->left->val;
                    q.push(temp->left);
                }
                if(temp->right){
                    res += temp->right->val;
                    q.push(temp->right);
                }
                
                if(temp->left){
                    temp->left->val = sum[lev] - res;
                }
                if(temp->right){
                    temp->right->val = sum[lev] - res;
                }
            }
            
        }
        return root;
    }
};