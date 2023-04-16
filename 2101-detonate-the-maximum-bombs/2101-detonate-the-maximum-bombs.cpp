#define ll long long
class Solution {
public:
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        map<int,vector<int>> adj;
        for(int i=0; i<bombs.size(); i++){
            for(int j=0; j<bombs.size(); j++){
                ll x1 = bombs[i][0], y1 = bombs[i][1];
                ll x2 = bombs[j][0], y2 = bombs[j][1];
                if(i!=j){
                    ll dis = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2); 
                    ll r = bombs[i][2];
                    if(dis <= r*r){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int n = bombs.size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<int> vis(n,0);
            if(vis[i] == 0){
                int cnt = 0;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()){
                    auto temp = q.front();
                    q.pop();
                    cnt++;
                    for(auto j:adj[temp]){
                        if(vis[j] == 0){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
                ans = max(ans,cnt);
            }
        }
        
        // for(auto i:adj){
        //     cout<<i.first<<":";
        //     for(auto j:i.second){
        //         cout<<j<<"-";
        //     }
        //     cout<<" ";
        // }
        // cout<<endl;
        
        return ans;
    }
};