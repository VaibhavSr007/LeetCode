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
    
    void solve (int n, vector <vector <TreeNode*>>& ans, vector <int>& z){
        
        if (z[n])
            return;
        z[n] = 1;
        
        for (int i=1; i<=n-2; i++)
        {
            solve (i, ans, z);
            solve (n-1-i, ans, z);
            for (int j=0; j<ans[i].size(); j++)
                for (int k=0; k<ans[n-1-i].size(); k++)
                    ans[n].push_back(new TreeNode(0, ans[i][j], ans[n-1-i][k]));                    
        }
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector <vector <TreeNode*>> ans(1+n);
        vector <int> z(1+n, 0);
        z[0] = z[1] = 1;
        ans[1].push_back(new TreeNode());
        solve (n, ans, z);
        return ans[n];
    }
    
};