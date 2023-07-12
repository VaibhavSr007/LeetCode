class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        
        int ans;
        if(prev == -1 || nums[idx] > nums[prev]){
            int pick = 1 + solve(idx+1, idx, nums, dp);
            int npick = solve(idx+1, prev, nums, dp);
            ans = max(pick,npick);
        }
        else{  // since we came here it means, prev is there and is smaller than present idx value
            ans = solve(idx+1, prev, nums, dp); // so we skip it
        }
        
        if(prev != -1){
            dp[idx][prev] = ans;
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(2500, vector<int>(2500,-1));
        return solve(0,-1, nums, dp);
    }
};