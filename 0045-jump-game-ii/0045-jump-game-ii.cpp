class Solution {
public:
    
    int solve(int idx, vector<int>& nums, vector<int> &dp){
        if(idx >= nums.size()-1){
            return 0;
        }
        
        if(nums[idx] == 0){
            return INT_MAX-1;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int res = INT_MAX-1;
        for(int i=idx+1; i<=nums[idx]+idx; i++){
            res = min(res,solve(i,nums,dp));
        }
        
        return dp[idx] = res+1;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0, nums, dp);
    }
};