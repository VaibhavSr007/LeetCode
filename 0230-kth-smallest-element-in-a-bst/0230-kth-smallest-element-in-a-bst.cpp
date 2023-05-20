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
    void inorder(TreeNode* root, int& i, int& ans, int k){
        if(root == NULL){
            return ;
        }
        

        inorder(root->left,i,ans,k);
        i++;
        if(i == k){
            ans = root->val;
            return ;
        }
        inorder(root->right,i,ans,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> v;
        // stack<TreeNode*> st;
        // inorder(root,v);
        
        // st.push(root);
        // while(true){
        //     if(root){
        //         st.push(root);
        //         root = root->left;
        //     }
        //     else{
        //         if(st.empty()){ break; }
        //         root = st.top();
        //         st.pop();
        //         v.push_back(root->val);
        //         root = root->right;
        //     }
        // }
        
        // return v[k-1];
        
        int ans = 0;
        int i =0;
        inorder(root,i,ans,k);
        
        return ans;
    }
};