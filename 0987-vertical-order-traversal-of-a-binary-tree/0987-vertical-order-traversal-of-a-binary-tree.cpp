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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            map<int,multiset<int>> mp1;
            
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                int dis = q.front().second;
                q.pop();
                
                mp1[dis].insert(node->val);
                
                if(node->left){
                    q.push({node->left, dis-1});
                }
                if(node->right){
                    q.push({node->right, dis+1});
                }
            }
            
            for(auto i:mp1){
                mp[i.first].insert(mp[i.first].end(), i.second.begin(),i.second.end());
            }
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};