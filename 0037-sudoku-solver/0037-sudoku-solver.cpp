class Solution {
public:
    
    bool isSafe(int x, int y, char c, vector<vector<char>>& grid){
        
        for(int i=0; i<9; i++){
            if(grid[x][i] == c){
                return false;
            }
        }
        
        for(int i=0; i<9; i++){
            if(grid[i][y] == c){
                return false;
            }
        }
        
        for(int i=(x/3)*3; i<((x/3)*3)+3; i++){
            for(int j=(y/3)*3; j<((y/3)*3)+3; j++){
                if(grid[i][j] == c){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& grid ){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                if(grid[i][j] == '.'){
                    
                    for(char c = '1'; c<='9'; c++){
                        
                        if(isSafe(i, j, c, grid)){
                            
                            grid[i][j] = c;
                            
                            if(solve(grid)){
                                return true;
                            }
                            grid[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};