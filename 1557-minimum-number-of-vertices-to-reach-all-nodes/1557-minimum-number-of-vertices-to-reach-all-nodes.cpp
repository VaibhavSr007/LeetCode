class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n,0), ans, v;
        queue<int> q;
        map<int, vector<int>> mp;
        map<int, vector<int>> mp1;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp1[i[1]].push_back(i[0]);
        }
        
        for(int i=0; i<n; i++){
            if(mp1.find(i) == mp1.end()){
                v.push_back(i);
            }
        }
        
        cout<<v.size()<<" ";
        for(auto i:v){
            // cout<<i<<" ";
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(i);
                ans.push_back(i);
                
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    for(auto j:mp[temp]){
                        if(vis[j] == 0){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                } 
            }
        }
        return ans;
    }
};