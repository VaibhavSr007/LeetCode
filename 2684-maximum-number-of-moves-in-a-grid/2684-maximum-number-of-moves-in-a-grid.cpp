class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        int R[3] = {-1, 0, 1};
        int C[3] = {1, 1, 1};
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i=0; i<grid.size(); i++){
            q.push({i,0,0});
        }
        // int cnt = 0;
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int cnt = q.front()[2];
            ans = max(ans,cnt);
            q.pop();
            vis[x][y] = 1;
            for(int k=0; k<3; k++){
                int new_x = x + R[k];
                int new_y = y + C[k];

                if(new_x >=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y] > grid[x][y] && vis[new_x][new_y] == 0){
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y,cnt+1});
                }
            }
        }
        return ans;
    }
};