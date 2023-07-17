class Solution {
public:
    int solve(int idx, int prev, set<int> &vis, vector<int>& nums, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        
        int ans;
        if(prev == -1 || prev != idx-1){
            int pick = nums[idx] + solve(idx+1, idx, vis, nums, dp);
            int npick = solve(idx+1, prev, vis, nums, dp);
            ans = max(pick, npick);
        }
        else{
            ans = solve(idx+1, prev, vis, nums, dp);
        }
        
        if(prev != -1){
            dp[idx][prev] = ans;
        }
        
        return ans;
    }
    
    int rob(vector<int>& nums) {
        set<int> prev;
        vector<vector<int>> dp(100, vector<int>(100, -1));
        return solve(0, -1, prev, nums, dp);
    }
};