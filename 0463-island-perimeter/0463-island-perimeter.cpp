class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        int C[4] = {0,-1,0,1};
        int R[4] = {1,0,-1,0};
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    continue;
                }
                if(grid[i][j]==1 && vis[i][j] == 0){
                    queue<vector<int>> q;
                    vis[i][j] = 1;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        int x = q.front()[0];
                        int y = q.front()[1];
                        int cnt = 0;
                        q.pop();
                        for(int k=0; k<4; k++){
                            int new_x = x + R[k];
                            int new_y = y + C[k];
                            
                            if(new_x >=0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y]==1){
                                if(vis[new_x][new_y] == 0){
                                    q.push({new_x,new_y});
                                    vis[new_x][new_y] = 1;
                                }
                                cnt++;
                            }
                        }
                        ans += (4-cnt);
                    }
                }
            }
        }
        return ans;
    }
};