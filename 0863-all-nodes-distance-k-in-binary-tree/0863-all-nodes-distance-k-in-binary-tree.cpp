/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> par;
    void search(TreeNode* root){
        
        if(root->left){
            par[root->left] = root;
            search(root->left);
        }
        if(root->right){
            par[root->right] = root;
            search(root->right);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        int cnt = 0;
        queue<TreeNode*> q;
        set<TreeNode*> vis;
        search(root);
        
        q.push(target);
        vis.insert(target);
        while(!q.empty()){
            
            int n = q.size();
            for(int i=0; i<n; i++){
                auto temp = q.front();
                q.pop();
                
                if(cnt == k){
                    v.push_back(temp->val);
                }
                
                if(vis.find(par[temp]) == vis.end() && par[temp] != NULL){
                    vis.insert(par[temp]);
                    q.push(par[temp]);
                }
                if(temp->left && vis.find(temp->left) == vis.end()){
                    vis.insert(temp->left);
                    q.push(temp->left);
                }
                if(temp->right && vis.find(temp->right) == vis.end()){
                    vis.insert(temp->right);
                    q.push(temp->right);
                }
            }
            cnt++;
            if(cnt > k){
                break;
            }
        }        
        
        return v;
    }
};