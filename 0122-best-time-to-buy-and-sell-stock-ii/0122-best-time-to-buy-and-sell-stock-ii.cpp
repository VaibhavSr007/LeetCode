class Solution {
public:
    int solve(int idx, int buy, vector<int> &nums, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return 0;
        }
        
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        
        int ans = 0;
        if(buy==1){
            int pick = solve(idx+1, 0, nums, dp) - nums[idx] ;
            int npick = solve(idx+1, buy, nums, dp);
            ans = max(pick, npick);
        }
        else{
            int pick = nums[idx]  + solve(idx+1, 1, nums, dp);
            int npick = solve(idx+1, buy, nums, dp);
            ans = max(pick, npick);
        }
        
        // for(int i=idx+1; i<nums.size(); i++){
        //     if(nums[i] - nums[idx] > 0)
        //         ans = max(ans, nums[i] - nums[idx] + solve(i, idx, nums, dp));
        // }
        // int ans1 = solve(idx+1, idx, nums,dp);
        
    
        
        return dp[idx][buy] =  ans;
    }
    
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, nums, dp);
    }
};