class Solution {
public:
    void solve(int i, int sum, vector<int> op, int n, vector<vector<int>> &ans){
        if(i > 9){
            if(sum == 0 && n==op.size()){
                ans.push_back(op);
            }
            return ;
        }
        
        op.push_back(i);
        solve(i+1, sum - i, op, n, ans);
        op.pop_back();
        solve(i+1, sum, op, n, ans);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(1, n, {}, k, ans);
        return ans;
    }
};