class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(int i, int j,int parent, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size(), m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j] <= parent){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a = dfs(i+1,j, grid[i][j], grid,dp);
        int b = dfs(i,j+1, grid[i][j], grid,dp);
        int c = dfs(i-1,j, grid[i][j], grid,dp);
        int d = dfs(i,j-1, grid[i][j], grid,dp);
        
        return dp[i][j] = (a+b+c+d+1)%MOD;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt = (cnt +  dfs(i,j,-1,grid,dp))%MOD;
            }
        }
        return cnt;
    }
};