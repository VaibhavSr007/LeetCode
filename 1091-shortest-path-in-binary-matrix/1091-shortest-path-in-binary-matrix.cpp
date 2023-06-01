class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int R[8] = {1, 0, -1, 0, 1, 1, -1, -1};
        int C[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<vector<int>> q;
        if(grid[0][0] == 1){ return -1;}
        q.push({0,0});
        vis[0][0] = 1;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp[0];
            int y = temp[1];
            if(x==n-1 && y==m-1){
                break;
            }
            
            for(int k=0; k<8; k++){
                int new_x = x + R[k];
                int new_y = y + C[k];
                
                if(new_x >=0 && new_y>=0 && new_x<n && new_y<m && grid[new_x][new_y]==0){
                    if(vis[new_x][new_y] == 0){
                        vis[new_x][new_y] = vis[x][y]+1;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        
        if(vis[n-1][n-1] == 0){
            return -1;
        }
        // cout<<vis[n-1][n-1]<<" ";
        return vis[n-1][n-1];
    }
};