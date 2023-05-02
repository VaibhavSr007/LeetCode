class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        map<int,vector<int>> mp;
        set<int> s;
        for(auto i:restricted){
            s.insert(i);
        }
        for(int i=0; i<edges.size(); i++){
            if(s.find(edges[i][0]) == s.end() && s.find(edges[i][1]) == s.end()){
                mp[edges[i][0]].push_back(edges[i][1]);
                mp[edges[i][1]].push_back(edges[i][0]);
            }
        }   
        
        // for(auto i:mp){
        //     cout<<i.first<<"->";
        //     for(auto j:i.second){
        //         cout<<j<<":";
        //     }
        //     cout<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        vector<int> vis(n,0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            ans += 1;
            q.pop();
            
            for(auto i:mp[temp]){
                if(vis[i] == 0){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        
        return ans;
    }
};