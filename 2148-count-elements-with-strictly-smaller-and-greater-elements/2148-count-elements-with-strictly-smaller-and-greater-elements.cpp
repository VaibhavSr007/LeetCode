class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> mp;
        vector<int> v;
        for(auto i:nums){
            if(mp.find(i) == mp.end()){
                v.push_back(i);
            }
            mp[i]++;
        }
        int ans = 0;
        sort(v.begin(),v.end());
        
        for(int i=1; i<v.size()-1; i++){
            if(v[i] < v[i+1] && v[i] > v[i-1]){
                ans += mp[v[i]];
            }
        }
        return ans;
    }
};