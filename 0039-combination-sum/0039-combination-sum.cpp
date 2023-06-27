class Solution {
public:
    void solve(int i, vector<int> &nums, vector<int> op, int tar, vector<vector<int>> &ans, int sum){
        
        if(i == nums.size()){
            if(sum == tar){
                ans.push_back(op);
            }
            return ;
        }
        
        if(sum > tar){
            return ;
        }
        
        op.push_back(nums[i]);
        solve(i, nums, op, tar, ans, sum+ nums[i]);
        op.pop_back();
        solve(i+1, nums, op, tar, ans, sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(0, candidates, {}, target, ans, 0);
        return ans;
    }
};