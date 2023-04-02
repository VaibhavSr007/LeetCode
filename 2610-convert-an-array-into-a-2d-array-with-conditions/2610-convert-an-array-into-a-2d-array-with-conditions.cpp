class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>  ans;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        while(mp.size()!=0){
            vector<int> v;
            for(auto i:mp){  
                v.push_back(i.first);
            }
            
            for(auto i:v){
                mp[i]--;
                if (mp[i] == 0){
                    mp.erase(i);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};