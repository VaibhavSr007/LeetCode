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
    void in(TreeNode* root, vector<int> &v){
        if(!root){
            return ;
        }
        
        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> v;
        in(root,v);
        
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        for(auto i:queries){
            int st=0;
            int en=v.size()-1;
            vector<int> res;
            bool chk = false;
            
            while(st <= en){
                int m = st + (en-st)/2;
                
                if(v[m] == i){
                    res.push_back(i);
                    res.push_back(i);
                    chk = true;
                    break;
                }
                else if(v[m] < i){
                    st = m+1;
                }
                else if(v[m] > i){
                    en = m-1;
                }
            }
            
            if(chk){
                // cout<<"x"<<" ";
                ans.push_back(res);
            }
            else{
                // cout<<i<<"->";
                // cout<<st<<":"<<en<<" ";
                --st;
                ++en;
                if(st >= 0){
                    res.push_back(v[st]);
                }
                else{
                    res.push_back(-1);
                }
                if(en < v.size()){
                    res.push_back(v[en]);
                }
                else{
                    res.push_back(-1);
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};