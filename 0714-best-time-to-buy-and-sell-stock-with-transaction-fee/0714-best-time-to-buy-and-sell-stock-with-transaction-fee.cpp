class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, int fee, vector<vector<int>> &dp){
        if(idx == prices.size())
            return 0;
        
        if(dp[idx][buy] != 0)
            return dp[idx][buy];
            
        int res = 0;
        if (buy == 0)
            res = solve(idx + 1, 1, prices, fee, dp) - prices[idx];
        else
            res = prices[idx] - fee + solve(idx + 1, 0, prices, fee, dp);
        
        res = max(res, solve(idx + 1, buy, prices, fee, dp));
        dp[idx][buy] = res;
        return res;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        return solve(0, 0, prices, fee, dp);
    }
};