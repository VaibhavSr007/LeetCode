class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mp;
        vector<int> cnt(numCourses, 0);
        queue<int> q;
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
            cnt[i[0]]++;
        }
        
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto dep:mp[node]){
                cnt[dep]--;
                if(cnt[dep] == 0){
                    q.push(dep);
                }
            }
        }
        
        if(count ==numCourses){
            return true;
        }
        
        return false;
    }
};