class Solution {
public:
    
    bool isValid(vector<vector<int>>& mat, int des, int p, int q){
        int n = mat.size(), m=mat[0].size();
        int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
        for (int i = 0; i < 8; i++) {
 
            int x = p + X[i];
            int y = q + Y[i];

            if (x >= 0 && y >= 0 && x < n && y < m
                && mat[x][y] == des){
                return true;
            }
        }
        return  false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        map<int, vector<int>> mp;
        int n = grid.size(), m=grid[0].size();
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                cout<<grid[i][j]<<" ";
                mp[grid[i][j]].push_back(i);
                mp[grid[i][j]].push_back(j);
            }
            cout<<endl;
        }
        cout<<endl;
        bool chk;
        
        for(int i=0; i<n*n-1; i++){
            int x = mp[i][0];
            int y = mp[i][1];
            if(!isValid(grid,i+1,x,y)){
                return false;
            }
        }
        return true;
    }
};