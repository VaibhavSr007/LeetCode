class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& Pvis, vector<vector<int>>& graph, vector<int>& chk){
        vis[node] = 1;
        Pvis[node] = 1;
        chk[node] = 0;
        for(auto i:graph[node]){
            if(vis[i]==0){
                if(dfs(i,vis,Pvis,graph,chk)){
                    return true;
                }
            }
            else if(Pvis[i]==1){
                return true;
            }
        }
        
        chk[node] = 1;
        Pvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> Pvis(n,0);
        vector<int> ans;
        vector<int> chk(n);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i,vis,Pvis,graph,chk);
            }
        }
        for(int i=0; i<n; i++){
            if(chk[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};