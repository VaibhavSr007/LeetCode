class Solution {
public:
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
//         int n = grid.size(), m = grid[0].size();
//         if(i<0 || j<0 || i>=n || j>=m){
//             return 0;
//         }
        
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int res1 = 0, res2 =0;
//         for(int idx=0; idx<n; idx++){
//             if(grid[i][j] < grid[idx][j]){
//                res1 = max(res1,solve(idx,j, grid, dp));
//             }
//         }
        
//         for(int idx=0; idx<m; idx++){
//             if(grid[i][j] < grid[i][idx]){
//                res2 = max(res2,solve(i,idx, grid, dp));   
//             }
//         }
        
//         return  dp[i][j] = 1 + max(res1,res2);
//     }
    
//     int maxIncreasingCells(vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();
//         vector<vector<int>> dp(n, vector<int>(m,-1));
//         int ans = 0;
//         for(int i=0; i<mat.size(); i++){
//             for(int j=0; j<mat[0].size(); j++){
//                 ans = max(ans, solve(i,j,mat,dp));
//             }
//         }
        
//         return ans;
//     }
    
    // 557 / 565 passed 
    
    int dfs(vector<vector<int>> &arr,int i,int j,map<int,vector<int>> row[],map<int,vector<int>> col[],vector<vector<int>> &dp){
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        //move in row
        auto c=row[i].lower_bound(arr[i][j]+1);
        if(c!=row[i].end()){
            vector<int> x=(*c).second;
            for(auto ele:x)
                ans=max(ans,1+dfs(arr,i,ele,row,col,dp));
        }
        //move in col
        auto r=col[j].lower_bound(arr[i][j]+1);
        if(r!=col[j].end()){
            vector<int> x=(*r).second;
            for(auto ele:x)
                ans=max(ans,1+dfs(arr,ele,j,row,col,dp));
        }
        return dp[i][j]=ans;
    }
    
    int maxIncreasingCells(vector<vector<int>>& arr) {
        
        int m=arr.size(),n=arr[0].size(),i,j;
        map<int,vector<int>> row[m];
        map<int,vector<int>> col[n];
        
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                int ele=arr[i][j];
                row[i][ele].push_back(j);
                col[j][ele].push_back(i);
            }
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=0;
       
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                ans=max(ans,dfs(arr,i,j,row,col,dp));
            }
        }
        return ans;
        
    }
};