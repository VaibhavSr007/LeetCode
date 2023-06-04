class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        map<int,vector<int> > mp;
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(i!=j && isConnected[i][j] == 1){
                    mp[i].push_back(j);
                }
            }
        }
        
        int n = isConnected.size();
        vector<int> vis(n,0);
        queue<int> q;
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(i);
                ans++;
                
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
            else{
                continue;
            }
        }
        
        return ans;
    }
};