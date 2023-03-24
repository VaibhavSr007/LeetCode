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
    vector<int> rightSideView(TreeNode* root) {
        
//         queue<TreeNode*> q;
//         vector<int> ans;
//         q.push(root);
        
//         if(root == NULL){
//             return ans;
//         }
        
//         while(!q.empty()){
//             int n = q.size();
            
//             for(int i=0; i<n; i++){
//                 auto temp = q.front();
//                 q.pop();
                
//                 if(i == n-1){
//                     ans.push_back(temp->val);
//                 }
                
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }
//         }
        
//         return ans;
        
        if(root == NULL){
            return {};
        }
    
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
   
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
       
            int lvl = temp.second;
       
            // if(mp.find(lvl) == mp.end()){
                mp[lvl] = temp.first->val;
            // }
       
            if(temp.first->left){
                q.push({temp.first->left,lvl+1});
            }
            if(temp.first->right){
                q.push({temp.first->right,lvl+1});
            }
        }
   
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
   
        return ans;
    }
};