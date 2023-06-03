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
    TreeNode* solve(int & st, int & en, vector<int> v){
        if(st >= en){
            return NULL;
        }
        
        int maxi = *max_element(v.begin()+st, v.begin()+en);
        int idx = -1;
        for(int i=st; i<en; i++){
            if(maxi == v[i]){
                idx = i;
                break;
            }
        }
        
        TreeNode*  temp = new TreeNode(maxi);
        
        temp->left  = solve(st,idx, v);
        idx += 1;
        temp->right  = solve(idx, en, v);
        idx -= 1;
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int st = 0, en = nums.size();
        
        return solve(st, en,nums);
        
        // int maxi = *max_element(nums.begin()+st, nums.begin()+1);
       
        // cout<<maxi<<" ";
        // return NULL;
    }
};