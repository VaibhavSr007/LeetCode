class Solution {
public:
    
    
    int solve(int i, int j, bool isA, vector<int>& nums, vector<vector<int>> &dp){
        
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans;
        if(isA){
            int st = nums[i] + solve(i+1, j, false, nums, dp);
            int en = nums[j] + solve(i, j-1, false, nums, dp);
            ans = max(st,en);
        }
        else{
            int st = - nums[i] + solve(i+1, j, true, nums, dp);
            int en = - nums[j] + solve(i, j-1, true, nums, dp);
            ans = min(st,en);
        }
        
        return dp[i][j] = ans;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(20, vector<int>(20,-1));
        int ans = solve(0, nums.size()-1, true, nums, dp);
        if(ans >= 0){
            return true;
        }
        return false;
    }
};