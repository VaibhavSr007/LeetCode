class Solution {
public:
    void solve(int idx, int n , int k, vector<int> &nums ,vector<vector<int>> &ans){
        
        if(nums.size() == k){
            ans.push_back(nums);
            return ;
        }
        
        if(idx == n){
            return ;
        }
        
        nums.push_back(idx);
        solve(idx+1, n, k, nums, ans);
        nums.pop_back();
        solve(idx+1, n, k, nums, ans);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(1, n+1, k, op, ans);
        return ans;
    }
};