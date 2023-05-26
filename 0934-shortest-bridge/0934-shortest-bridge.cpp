class Solution {
public:
    int R[4] = {1,0,-1,0};
    int C[4] = {0,1,0,-1};
    
    vector<vector<int>> paint(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, 
        queue<vector<int>> q1){
        
        vector<vector<int>> v;
        v.push_back({i,j});
        int n = grid.size(), m = grid[0].size();
        while(!q1.empty()){
            int x = q1.front()[0];
            int y = q1.front()[1];
            q1.pop();

            for(int k=0; k<4; k++){
                int new_x = x + R[k];
                int new_y = y + C[k];

                if(new_x >= 0 && new_x < n && new_y >=0 && new_y < m && grid[new_x][new_y]==1){
                    if(vis[new_x][new_y] == 0){
                        q1.push({new_x, new_y});
                        v.push_back({new_x,new_y});
                        vis[new_x][new_y] = 1;
                    }
                }
            }
        }
        return v;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> vis (n, vector<int> (m,0)), first, second;
        queue<vector<int>> q;
        bool chk = false;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vector<vector<int>> v = paint(i,j,grid,vis,q);
                    vis[i][j] = 1;
                    if(cnt == 0){
                        first = v;
                    }
                    else{
                        second = v;
                    }
                    cnt++;
                }
            }
        }
        
        
        int ans = INT_MAX;
        for(int i=0; i<first.size(); i++){
            for(int j=0; j<second.size(); j++){
                ans = min(ans,(abs(first[i][0] - second[j][0]) + abs(first[i][1] - second[j][1]))-1);
            }
        }
               
        return ans;
    }
};