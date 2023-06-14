class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        int n = grid1.size(), m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> vis1(n, vector<int>(m,0));
        queue<vector<int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid1[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty()){
                        int x = q.front()[0];
                        int y = q.front()[1];
                        q.pop();

                        for(auto x:dir){
                            int new_x = x[0];
                            int new_y = x[1];

                            if(new_x >= 0 && new_y>=0 && new_x<n && new_y<m && grid1[new_x][new_y] == 1 && vis[new_x][new_y] == 0){
                                q.push({new_x,new_y});
                                vis[new_x][new_y] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        // here we have got the first grid visited
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && vis1[i][j] == 0 && vis[i][j] == 1){
                    q.push({i,j});
                    vis1[i][j] = 1;
                    bool chk = true;

                    while(!q.empty()){
                        int x = q.front()[0];
                        int y = q.front()[1];
                        q.pop();

                        for(auto d:dir){
                            int new_x = x+d[0];
                            int new_y = y+d[1];

                            if(new_x >= 0 && new_y>=0 && new_x<n && new_y<m && grid2[new_x][new_y] == 1 && vis1[new_x][new_y] == 0){
                                if(vis[new_x][new_y] == 0){
                                    chk = false;
                                    q.push({new_x,new_y});
                                    vis1[new_x][new_y] = 1;
                                }
                                else{
                                    q.push({new_x,new_y});
                                    vis1[new_x][new_y] = 1;
                                }
                                
                            }
                        }
                    }
                    if(chk){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};