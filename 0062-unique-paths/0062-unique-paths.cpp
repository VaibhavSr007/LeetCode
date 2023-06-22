class Solution {
public:
    
    int solve(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i >= n || j >= m){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int r = solve(i, j+1, n, m, dp);
        int d = solve(i+1, j, n, m, dp);
        
        dp[i][j] = r + d;
        return r + d;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};