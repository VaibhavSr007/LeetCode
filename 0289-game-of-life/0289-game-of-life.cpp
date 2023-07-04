class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> grid(board);
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,-1}, {-1,1}, {-1,-1}, {1,1}};
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
                
                if(board[i][j] == 0){
                    int cnt = 0;
                    for(auto d:dir){
                        int x = d[0] + i;
                        int y = d[1] + j;
                        
                        if(x>=0 && y>=0 && x<n && y<m && board[x][y] == 1){
                            cnt++;
                        }
                    }
                    if(cnt == 3){
                        grid[i][j] = 1;
                    }
                }
                else{
                    int cnt = 0, cnt1 = 0;
                    for(auto d:dir){
                        int x = d[0] + i;
                        int y = d[1] + j;
                        
                        if(x>=0 && y>=0 && x<n && y<m){
                            if(board[x][y] == 1)
                                cnt++;
                        }
                    }
                    if(cnt < 2){
                        grid[i][j] = 0;
                    }
                    else if(cnt > 3){
                        grid[i][j] = 0;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = grid[i][j];
            }
        }
    }
};