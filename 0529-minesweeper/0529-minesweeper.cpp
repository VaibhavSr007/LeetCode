class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        vector<vector<int>> dir= {{1,0},{-1,0},{0,1},{0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};
        int n=  board.size(), m = board[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        q.push({click[0],click[1]});
        vis[click[0]][click[1]] = -1;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int cnt = 0;
            vector<vector<int>> v;
            
            for(auto d:dir){
                int x = d[0] + temp[0];
                int y = d[1] + temp[1];
                
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y] == 0){
                    if(board[x][y] == 'M'){
                        cnt++;
                    }
                    v.push_back({x,y});
                }
            }
            
            if(cnt != 0){
                vis[temp[0]][temp[1]] = cnt;
            }
            else{
                for(auto i:v){
                    if(board[i[0]][i[1]] == 'E'){
                        q.push(i);
                        vis[i[0]][i[1]] = -1;
                    }
                   
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'M'){
                    board[i][j] = 'M';
                }
                else if(board[i][j] >= '1' && board[i][j] <= '8'){
                    continue;
                }
                else if(board[i][j] == 'B'){
                    continue;
                }
                else if(vis[i][j] == -1){
                    board[i][j] = 'B';
                }
                else if(vis[i][j] >= 1){
                    board[i][j] = '0'+ (vis[i][j]);
                }
                else if(vis[i][j] == 0){
                    board[i][j] = 'E';
                }
            }
            // cout<<endl;
        }
        // cout<<endl;
        return board;
    }
};