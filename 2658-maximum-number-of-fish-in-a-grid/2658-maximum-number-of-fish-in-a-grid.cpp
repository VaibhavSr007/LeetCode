class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        // queue<int> q;
        int R[4] = {1,-1,0,0};
        int C[4] = {0,0,-1,1};
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                    continue;
                }
                else if(vis[i][j] == 1){
                    continue;
                }
                
                queue<vector<int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                int cnt = 0;
                while(!q.empty()){
                    int x = q.front()[0];
                    int y = q.front()[1];
                    q.pop();
                    cnt += grid[x][y];
                    for(int k=0; k<4; k++){
                        int new_x = x + R[k];
                        int new_y = y + C[k];
                        
                        if(new_x >=0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] != 0){
                            if(vis[new_x][new_y] == 0){
                                vis[new_x][new_y] = 1;
                                q.push({new_x,new_y});
                            }
                        }
                    }
                }
                // cout<<cnt<<" ";
                ans =  max(ans,cnt);
            }  
        }
        return ans;
    }
};