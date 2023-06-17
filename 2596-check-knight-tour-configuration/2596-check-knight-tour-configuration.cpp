class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> d = {{2,1},{-2,1},{2,-1},{-2,-1},{-1,-2}, {-1,2},{1,-2},{1,2}};
        if(grid[0][0] != 0){
            return false;
        }
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            for(auto i:d){
                int x = temp[0] + i[0];
                int y = temp[1] + i[1];
                
                if(x<n && y<n && x>=0 && y>=0 && grid[x][y]==grid[temp[0]][temp[1]]+1 && vis[x][y] ==0){
                    vis[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        
        for(auto i:vis){
            for(auto j:i){
                if(j==0){
                    return false;
                }
            }
        }
        return true;
    }
};