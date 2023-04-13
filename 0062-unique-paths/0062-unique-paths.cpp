class Solution {
public:
    
    void solve(int x, int y, vector<vector<int>>& vis, int n, int m, long long& ans, string op){
        if(x == n-1 && y == m-1){
            ans += 1;
            return ;
        }
        
        vis[x][y] = 1;
        
        int new_x = x+1;
        int new_y = y;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && vis[new_x][new_y]==0){
            op.push_back('D');
            solve(new_x,new_y,vis,n,m,ans,op);
            op.pop_back();
        }
        
        new_x = x;
        new_y = y+1;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && vis[new_x][new_y]==0){
            op.push_back('R');
            solve(new_x,new_y,vis,n,m,ans,op);
            op.pop_back();
        }
        
        vis[x][y] = 0;
    }
    
    long long int uniquePaths(int n, int m) {
        
        // long long int total_paths = m+n-2; //total direction of movement in right(m-1) n down(n-1) so tot m+n-2
        // double res = 1;
        // int x = m-1;
        // for(int i=1; i<m; i++){ // total combinations of right or down directions among total paths
        //     res *= (total_paths -x + i);  // tot C tot_down or tot C tot_right
        //     res /= (i);
        // }
        // return int(res);
        
        
        // int x = 0, y=0;
        // long long ans=0;
        // vector<vector<int>> vis(n,vector<int> (m,0));
        // string op = "";
        // solve(x,y,vis,n,m, ans, op);
        // return ans;
        
        int tot = n+m-2;
        int r = n-1;
        long long res = 1;
        for(int i=1; i<=r; i++){
            res *= long(tot - r + i);
            res /= i;
        }
        return res;
    }
};