class Solution {
public:
    bool isSafe(int i, int j, vector<string> vis){
        int n = vis.size();
        
        int x = i, y = j;  // up-left
        while(x>=0 && x<n && y>=0 && y<n){
            if(vis[x][y] == 'Q'){
                return false;
            }
            x = x-1;
            y = y-1;
        }
        
        x = i, y = j; // up
        while(x>=0 && x<n && y>=0 && y<n){
            if(vis[x][y] == 'Q'){
                return false;
            }
            x = x-1;
        }
        
        x = i, y = j; //up-right
        while(x>=0 && x<n && y>=0 && y<n){
            if(vis[x][y] == 'Q'){
                return false;
            }
            x = x-1;
            y = y+1;
        }
        
        return true;
    }
    
    vector<vector<string>> ans;
    void solve(int i, vector<string> vis){
        
        if(i == vis.size()){
            ans.push_back(vis);
            return ;
        }
        
        
        for(int idx = 0; idx<vis.size(); idx++){
            if(isSafe(i,idx, vis)){
                vis[i][idx] = 'Q';
                solve(i+1, vis);
                vis[i][idx] = '.';
            }  
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> vis(n, s);
        solve(0,vis);
        return ans;
    }
};