class Solution {
public:
    
    bool solve(int idx, vector<int>& nums, vector<int> &dp){
        if(idx >= nums.size()-1){
            return true;
        }
        
        if(nums[idx] == 0){
            return false;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        for(int i=idx+1; i<=nums[idx]+idx; i++){
            
            if(solve(i, nums, dp)){
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = 0;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true;
        }
        vector<int> dp(n+1,-1);
        return solve(0,nums, dp);
    }
};