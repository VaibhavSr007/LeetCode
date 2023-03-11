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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        
        map<int,vector<pair<int,int>>> mp;
        for(int i=0; i<desc.size(); i++){
            if(desc[i][2]==1){
                mp[desc[i][0]].push_back({desc[i][1],1});
            }
            else{
                mp[desc[i][0]].push_back({desc[i][1],0});
            } 
        }
        
        set<int> s;
        for(auto i:desc){
            s.insert(i[1]);
        }
        int root_val;
        for(auto i:desc){
            if(s.find(i[0])==s.end()){
                root_val = i[0];
            }
        }
        // // cout<<root_val<<" ";
        // for(auto i:mp){
        //     cout<<i.first<<":";
        //     for(auto j:i.second){
        //         cout<<j.first<<"-"<<j.second<<" ";
        //     }
        //     cout<<endl;
        // }
        
        TreeNode *root = new TreeNode(root_val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            for(auto child:mp[temp->val]){
                if(child.second==1){
                    TreeNode *left = new TreeNode(child.first);
                    temp->left = left;
                    q.push(left);
                }
                else{
                    TreeNode *right = new TreeNode(child.first);
                    temp->right = right;
                    q.push(right);
                }
            }
        }
        
        
        return root;
    }
};