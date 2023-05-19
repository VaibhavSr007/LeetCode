class Solution {
public:
    bool dfs(int node, int p_col, vector<vector<int>>& graph, vector<int>& color){
        color[node] = !p_col;
        bool x = true;
        for(auto i:graph[node]){
            if(color[i] == -1){
                color[i] = !color[node];
                x &= dfs(i,color[node],graph,color);
            }
            else if(color[i] == color[node]){
                return false;
            }
        }  
        return x;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        int p_col = 0;
        for(int i=0; i<graph.size(); i++){
            if(color[i] == -1 && !dfs(i,1,graph,color)){
                return false;
            }
        }
        return true;
    }
};