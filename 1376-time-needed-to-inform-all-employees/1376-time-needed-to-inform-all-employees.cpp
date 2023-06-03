class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            if(manager[i] != -1)
                mp[manager[i]].push_back(i);
        }
        
        // for(auto i:mp){
        //     cout<<i.first<<"->";
        //     for(auto j:i.second){
        //         cout<<j<<":";
        //     }
        //     cout<<" ";
        // }
        // cout<<endl;
        
        queue<vector<int>> q;
        q.push({headID,informTime[headID]});
        int ans = INT_MIN;
        
        while(!q.empty()){
            int x = q.size();
            
            for(int i=0; i<x; i++){
                auto temp = q.front();
                q.pop();
                if(informTime[temp[0]] == 0)
                    ans = max(ans, temp[1]);
                
                for(auto j:mp[temp[0]]){
                    q.push({j, temp[1] + informTime[j]});
                }
            }
        }
        return ans;
    }
};