class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    int cnt = 0;
                    bool chk = false;
                    while(!q.empty()){
                        auto temp = q.front();
                        int x = temp[0];
                        int y = temp[1];
                        q.pop();
                        cnt++;
                        
                        for(int a=0; a<n; a++){
                            if(vis[a][y] == 0 && grid[a][y] == 1){
                                q.push({a,y});
                                vis[a][y] = 1;
                                chk = true;
                            }
                        }
                        for(int a=0; a<m; a++){
                            if(vis[x][a] == 0 && grid[x][a] == 1){
                                q.push({x,a});
                                vis[x][a] = 1;
                                chk = true;
                            }
                        }
                    }
                    if(cnt != 1)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};