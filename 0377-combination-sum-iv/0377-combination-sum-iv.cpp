class Solution {
public:
    int solve(int idx, int tar, vector<int> &nums, vector<int> &dp){
        
        if(tar == 0){
            return 1;
        }
        else if(tar < 0){
            return 0;
        }
        
        if(dp[tar] != -1){
            return dp[tar];
        }
        
        int take = 0;
        for(int i=0; i<nums.size(); i++){
            take +=  solve(i, tar-nums[i], nums, dp);
        }
        
        return dp[tar] = take;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001,-1);
        return solve(0, target, nums, dp);
    }
};