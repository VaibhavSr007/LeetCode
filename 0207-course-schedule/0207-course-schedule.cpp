class Solution {
public:
    
    bool dfs(int idx, vector<int> &vis, map<int,vector<int>> &mp, vector<int> dvis, vector<int> &dp){
        
        vis[idx] = 1;
        dvis[idx] = 1;
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        for(auto i:mp[idx]){
            if(dvis[i] == 1){
                return true;
            }
            else{
                if(dfs(i, vis, mp, dvis, dp)){
                    return true;
                }
            }
        }
        dvis[idx] = 0;
        
        dp[idx] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> vis(n, 0);
        map<int, vector<int>> mp;
        for(auto i:prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                vector<int> dvis(n, 0);
                vector<int> dp(n, -1);
                if(dfs(i, vis, mp, dvis, dp)){
                    return false;
                }
            }
        }
        
        return true;
        
//         queue<int> q;
//         set<int> s;
//         map<int, vector<int>> mp;
//         vector<int> dependency(numCourses, 0);
        
//         for(auto i:prerequisites){
//             mp[i[1]].push_back(i[0]);
//             dependency[i[0]]++;
//         }
        
//         for(int i=0; i<numCourses; i++){
//             if(dependency[i] == 0){
//                 s.insert(i);
//                 q.push(i);
//             }
//         }
        
        
        
//         while(!q.empty()){
//             auto temp = q.front();
//             q.pop();

//             for(auto i:mp[temp]){
//                 dependency[i]--;
//                 if(dependency[i] == 0){
//                     s.insert(i);
//                     q.push(i);
//                 }
//             }
//         }
        
//         if(s.size() != numCourses){
//             return false;
//         }
        
//         return true;
    }
};