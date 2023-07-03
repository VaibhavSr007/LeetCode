class Solution {
public:
    bool solve(int node, int n, vector<int> &ans, map<int, vector<int>> &mp){
        if(node == n){
            return true;
        }
        
        
        for(int i=1; i<=4; i++){
            
            bool chk = true;
            for(auto n:mp[node]){
                if(i == ans[n]){
                    chk = false;
                    break;
                }
            }
            if(chk){
                ans[node] = i;
                if(solve(node+1, n, ans, mp)){
                    return true;
                }
                ans[node] = -1;
            }
        }
        
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        if(paths.size() == 0){
            vector<int> ans(n,1);
            return ans;
        }
        
        vector<int> ans(n,-1);
        map<int, vector<int>> mp;
        for(auto i:paths){
            mp[i[0]-1].push_back(i[1]-1);
            mp[i[1]-1].push_back(i[0]-1);
        }
        
        solve(0, n, ans, mp);
        return ans;
    }
};