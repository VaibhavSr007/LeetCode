class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}};
    
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        
        if(i == m-1 && j == n-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0,0, m, n, dp);
//         
//         queue<vector<int>> q;
       
//         int ans= 0;
        
//         q.push({0,0});
//         while(!q.empty()){
//             vector<int> temp = q.front();
//             q.pop();

//             if(temp[0] == m-1 && temp[1] == n-1){
//                 ans++;
//             }

//             for(auto d:dir){
//                 int x = d[0] + temp[0];
//                 int y = d[1] + temp[1];

//                 if(x>=0 && y>=0 && x<m && y<n){
//                     q.push({x,y});
//                 }
//             }
//         }
        
//         return ans;
    }
};