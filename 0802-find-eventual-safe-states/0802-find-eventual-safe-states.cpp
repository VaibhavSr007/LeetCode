class Solution {
public:
    int solve(int idx, vector<vector<int>>& graph, vector<int> &dp, vector<int> &vis){
        
        if(vis[idx] == 1){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        vis[idx] = 1;
        int ans = 1;
        for(auto i:graph[idx]){
            
            int c = solve(i, graph, dp, vis);
            // cout<<i<<" ";
            ans = ans & c;
            
        }
        vis[idx] = 0;
        return  dp[idx] = ans;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1);
        vector<int>  ans;
    
        
        
        for(int i=0; i<n; i++){
            vector<int> vis(n, 0);
            solve(i, graph, dp, vis);
            if(dp[i] == 1){
                ans.push_back(i);
            }
        }
        // cout<<endl;
        return ans;
    }
};