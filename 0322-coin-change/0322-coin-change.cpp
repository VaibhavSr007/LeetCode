class Solution {
public:
    
    int solve(int i, vector<int>& nums, int sum, vector<vector<int>> &dp){
        if(sum == 0){
            return 0;
        }
        if(i<0 || sum < 0){
            return INT_MAX-1;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        int take = 1 + solve(i, nums, sum-nums[i], dp);
        int no = solve(i-1, nums, sum, dp);
        
        return dp[i][sum] = min(no,take);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());  // this is just an optimization
        vector<vector<int>> dp(13, vector<int>(10001, -1));
        int ans = solve(coins.size()-1,coins,amount, dp);
        if(ans == INT_MAX-1){
            return -1;                        
        }
        return ans;
        
    }
};