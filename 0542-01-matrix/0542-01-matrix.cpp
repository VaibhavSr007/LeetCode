class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& mat){
        int n= mat.size(), m = mat[0].size();
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int DR[4] = {1,-1,0,0};
        int DC[4] = {0,0,-1,1};
        int n= mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }
    
        
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int dist = q.front()[2];
            q.pop();
                        
            for(int k=0; k<4; k++){
                int new_x = DR[k] + x;
                int new_y = DC[k] + y;
                            
                if(isValid(new_x,new_y,mat)){
                    if(vis[new_x][new_y] == 0){
                        vis[new_x][new_y] = 1;
                        q.push({new_x,new_y,dist+1});
                        ans[new_x][new_y] = dist+1;
                    }
                }
            }
        }
        
        return ans;
    }
};