class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        
        for(int x=0; x<9; x++){
            for(int y=0; y<9; y++){
                
                if(grid[x][y] != '.'){
                    char c = grid[x][y];
                    
                    for(int i=0; i<9; i++){
                        if(i != y && grid[x][i] == c){
                            return false;
                        }
                    }

                    for(int i=0; i<9; i++){
                        if(i != x && grid[i][y] == c){
                            return false;
                        }
                    }

                    for(int i=(x/3)*3; i<((x/3)*3)+3; i++){
                        for(int j=(y/3)*3; j<((y/3)*3)+3; j++){
                            if(i!=x && y!=j && grid[i][j] == c){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};