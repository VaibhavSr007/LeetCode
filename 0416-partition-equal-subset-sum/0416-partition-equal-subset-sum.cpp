class Solution {
public:
    
    bool solve(int idx, vector<int>& nums, int sum, int tot, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(tot - sum == sum){
                return true;
            }
            return false;
        }
        
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        if(solve(idx+1, nums, sum+nums[idx], tot, dp)){
            return true;
        }
        if(solve(idx+1, nums, sum, tot, dp)){
            return true;
        }
        
        return dp[idx][sum] = false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(20000, -1));
        int tot= 0;
        for(auto i:nums){ tot += i;}
        return solve(0, nums, 0, tot, dp);
    }
};