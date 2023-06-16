class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size(), cnt = 0;
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    bool  chk = true;
                    
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        for(auto d:dir){
                            int x = temp[0] + d[0];
                            int y = temp[1] + d[1];
                            
                            if(x>=0 && y>=0 && x<n && y<m){
                                if(grid[x][y] == 0 && vis[x][y] == 0){
                                    q.push({x,y});
                                    vis[x][y] = 1;
                                }
                            }
                            else{
                                chk = false;
                            }
                        }
                        
                    }
                    if(chk){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};