class Solution {
public:
    
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool dfs (int i, int j, vector<vector<int>> &grid){
        int n= grid.size(),  m = grid[0].size();
                                                                                 
        if(i==n-1){
            return true;
        }
    
        grid[i][j] = -1;
        for(auto d:dir){
            int x = d[0] + i;
            int y = d[1] + j;
            
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 0){
                
                if(dfs(x, y, grid)){
                    return true;
                }
            }
        }
        
        return false;
                                            
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n = row, m = col, res = 0;
        
        bool ans = false;
        int low = 0, high = cells.size()-1;
        while(low < high){
            
            int mid = high - (high-low)/2;
            vector<vector<int>> grid(row, vector<int>(col,0));
            for(int i=0; i<mid; i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            
            ans = false;
            for(int i=0; i<m; i++){
                if(grid[0][i] == 0){
                    ans = dfs(0,i, grid);
                }
                if(ans){
                    res = mid;
                    low = mid;
                    break;
                }
            }

            if(!ans){
                high = mid-1;
            }
            
        }
            
        return res;
    }
};