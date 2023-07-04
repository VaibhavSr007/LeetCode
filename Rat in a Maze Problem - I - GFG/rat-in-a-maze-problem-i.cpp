//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
   
    // bool is_safe(vector<vector<int>> &m, int x, int y,vector<vector<int>> vis, int n){
    //     if((x>=0 && x<=n-1) && (y>=0 && y<=n-1) && vis[x][y]==0 && m[x][y]==1){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    
    // void solve(vector<vector<int>> &m, vector<string>& ans, vector<vector<int>>& vis, string& op, int x, int y, int n){
    //     if(x==n-1 && y==n-1){ // base condition when we reached at destination
    //         ans.push_back(op);
    //         return ;
    //     }
        
    //     vis[x][y] = 1;       // making visted index 1 so to not visit again
        
        
    //     // 4 directions 4 conditions 
    //     // Down
    //     int new_x = x+1;
    //     int new_y = y;
    //     if(is_safe(m,new_x,new_y,vis,n)){  // checking if the next path safe or not
    //         op.push_back('D');
    //         solve(m,ans,vis,op,new_x,new_y,n); // recursive call
    //         op.pop_back();                     // backtrack
    //     }
    //     // Left
    //     new_x = x;
    //     new_y = y-1;
    //     if(is_safe(m,new_x,new_y,vis,n)){
    //         op.push_back('L');
    //         solve(m,ans,vis,op,new_x,new_y,n);
    //         op.pop_back();
    //     }
    //     // Right
    //     new_x = x;
    //     new_y = y+1;
    //     if(is_safe(m,new_x,new_y,vis,n)){
    //         op.push_back('R');
    //         solve(m,ans,vis,op,new_x,new_y,n);
    //         op.pop_back();
    //     }
    //     // up
    //     new_x = x-1;
    //     new_y = y;
    //     if(is_safe(m,new_x,new_y,vis,n)){
    //         op.push_back('U');
    //         solve(m,ans,vis,op,new_x,new_y,n);
    //         op.pop_back();
    //     }
        
    //     vis[x][y] = 0;  // making visted zero so to check for the other paths available
    // }
    
    vector<vector<int>> dir = {{1,0,1}, {0,-1,2}, {-1,0,3}, {0,1,4}};
    void solve(int i, int j, string s, vector<vector<int>> vis, vector<string> & ans, vector<vector<int>> &grid){
        int n = vis.size();
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return ;
        }
        
        
        vis[i][j] = 1;
        for(auto d:dir){
            int x = d[0] + i;
            int y = d[1] + j;
            
            if(x>=0 && y>=0 && x<n && y<n && vis[x][y] == 0 && grid[x][y] == 1) {
                
                if(d[2] == 1){
                    s.push_back('D');
                }
                else if(d[2] == 2){
                    s.push_back('L');
                }
                else if(d[2] == 3){
                    s.push_back('U');
                }
                else if(d[2] == 4){
                    s.push_back('R');
                }
                
                solve(x,y,s,vis,ans, grid);
                
                s.pop_back();
            }
        }
        
        vis[i][j] = 0;
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
    //   vector<string> ans;
    //   vector<vector<int>> vis(m);
       
    //   for(int i=0; i<n; i++){
    //       for(int j=0; j<n; j++){      // initialzing the visited vector with zero
    //           vis[i][j] = 0;
    //       }
    //   }
    //   int x=0;   // starting source index o,o
    //   int y=0;
       
    //   string op = "";  // string to store the direction
       
    //   if(m[x][y]==0){
    //       return ans;  // if the source itself is not 1 so it cant start itself
    //   }
       
    //   solve(m,ans,vis,op,x,y,n);    // finction call
       
    //   return ans;
    
    if(m[0][0] == 0){
        return {};
    }
    
    vector<string> ans;
    string s = "";
    vector<vector<int>> vis(n, vector<int>(n,0));
    solve(0,0,s,vis,ans,m);
    return ans;
    
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends