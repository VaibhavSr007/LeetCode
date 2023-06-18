class Solution {
public:
    
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
        
        return dp[i][j] = max(a,max(b,max(c,d)))+1;
        
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 0;
                cnt = dfs(i,j,-1,grid,dp);
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};