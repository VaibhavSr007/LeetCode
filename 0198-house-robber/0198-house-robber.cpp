class Solution {
public:
    int solve(int n, vector<int>& dp, vector<int>&nums){
        if(n==0){
            return nums[n];
        }
        if(n<0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        int pick = nums[n] + solve(n-2,dp,nums);
        int no_pick = solve(n-1,dp,nums);
        
        dp[n] = max(pick,no_pick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        
//         if(nums.size()==1) return nums[0];
    
//         vector<int> dp(nums.size());
    
//         dp[0] = nums[0];
//         dp[1] = max(dp[0], nums[1]);
    
//         for(int i=2; i<nums.size(); i++){
//             dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
//         }
        
//         return dp[nums.size()-1];
        
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return solve(n,dp,nums);
    
    }
};