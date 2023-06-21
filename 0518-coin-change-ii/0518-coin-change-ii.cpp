class Solution {
public:
    
     int solve(int idx, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum == 0){
            return 1;
        }
        
        if(sum < 0 || idx < 0){
            return 0;
        }
         
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        int res;
        if(sum >= nums[idx]){
            int take = solve(idx, sum-nums[idx], nums,dp);
            int no_take = solve(idx-1, sum, nums,dp);
            res = take + no_take;
        }
        else{
            res = solve(idx-1, sum, nums,dp);
        }
        
        return dp[idx][sum] = res;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};