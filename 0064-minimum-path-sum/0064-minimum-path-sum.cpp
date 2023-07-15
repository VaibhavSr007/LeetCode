class Solution {
public:
    int solve(int i, int j , vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size(), m = grid[0].size();
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        
        
        if(i<0 || j<0 || i>=n || j>=m){
            return INT_MAX;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right =  solve(i, j+1, grid, dp);
        int down = solve(i+1, j, grid, dp);
        
        dp[i][j] =  grid[i][j] + min(right, down);
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, grid, dp);
    }
};