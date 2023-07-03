//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool solve(int node, vector<int> vis, int n, int m, map<int,vector<int>> &mp){
        
        if(node == n){
            return true;
        }   
        
        
        
        for(int i=1; i<=m; i++){
            
            bool chk = true;
            for(auto n:mp[node]){
                if(vis[n] == i){
                    chk = false;
                    break;
                }
            }
            if(chk){
                vis[node] = i;
                if(solve(node+1, vis, n, m, mp)){
                    return true;
                }
                vis[node] = -1;
            }
            
        }
        
        return false;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        
        vector<int> v(n,-1);
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == 1){
                    mp[i].push_back(j);
                }
            }
        }
        
        return solve(0, v, n, m, mp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends