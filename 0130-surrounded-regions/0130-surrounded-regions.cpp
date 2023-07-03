class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int n = board.size(), m = board[0].size();
        
        queue<vector<int>> q;
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<board[0].size(); j++){
                if( (i== n-1 || i==0 || j==0 || j==m-1) && board[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                    
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        
                        for(auto d:dir){
                            int x = d[0] + temp[0];
                            int y = d[1] + temp[1];
                            
                            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && board[x][y]=='O'){
                                q.push({x,y});
                                vis[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
            
        }
    }
};