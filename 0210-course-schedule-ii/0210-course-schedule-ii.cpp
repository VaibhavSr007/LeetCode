class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> s;
        map<int, vector<int>> mp;
        vector<int> dependency(numCourses, 0);
        
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
            dependency[i[0]]++;
        }
        
        for(int i=0; i<numCourses; i++){
            if(dependency[i] == 0){
                s.push_back(i);
                q.push(i);
            }
        }
        
        
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(auto i:mp[temp]){
                dependency[i]--;
                if(dependency[i] == 0){
                    s.push_back(i);
                    q.push(i);
                }
            }
        }
        
        if(s.size() != numCourses){
            return {};
        }
        
        return s;
    }
};