class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();

            for(int x=0; x<size; x++){
                auto temp = q.front();
                q.pop();
                
                for(auto i:dir){
                    int x = i[0] + temp[0];
                    int y = i[1] + temp[1];
                    
                    if(x >= 0 && y>=0 && x<n && y<m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            cnt++;
        }
        
        for(auto i:grid){
            for(auto j:i){
                if(j == 1){
                    return -1;
                }
            }
        }
        
        return cnt == 0 ? 0 : cnt-1;
    }
};