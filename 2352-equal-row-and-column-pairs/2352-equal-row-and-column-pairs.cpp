class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            mp[grid[i]]++;
        }
        
        for(int i=0; i<grid.size(); i++){
            vector<int> v;
            for(int j=0; j<grid.size(); j++){
                v.push_back(grid[j][i]);
            }
            if(mp.find(v) != mp.end()){
                ans += mp[v];
            }
        }
        return ans;
    }
};