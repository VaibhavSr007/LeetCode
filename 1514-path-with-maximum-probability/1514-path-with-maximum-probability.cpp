class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {       
        map<int, vector<pair<int,double>>> mp;
        for(int i=0; i<edges.size(); i++){
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> v(n, 0.0);
        v[start] = 1.0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i:mp[node]){
                double prob = v[node] * i.second;
                if(prob > v[i.first]){
                    q.push(i.first);
                    v[i.first] = prob;
                }
            }
        }
        
        
        return v[end];
    }
};