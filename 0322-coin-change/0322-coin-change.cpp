class Solution {
public:
    int solve(int idx, vector<int>& nums, int amt, vector<vector<int>> &dp){
        if(amt == 0){
            return 0;
        }
        
        if(amt < 0 || idx == nums.size()){
            return INT_MAX-1;
        }
        
        if(dp[idx][amt] != -1){
            return dp[idx][amt];
        }
        
        int pick = 1 + solve(idx, nums, amt-nums[idx], dp);
        int npick = solve(idx+1, nums, amt, dp);
        
        
        return dp[idx][amt] = min(pick, npick);
        
    }
    
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans =  solve(0, nums, amount, dp);
        return ans == INT_MAX-1 ? -1 : ans ;
        
    }
};