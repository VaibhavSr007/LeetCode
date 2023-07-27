class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int sum = 0, cnt= 0;
        map<int,int> mp;
        
        for(auto i:nums){
            sum += i;
            
            if(sum == k){
                cnt++;
            }
            
            if(mp.find(sum-k) != mp.end()){
                cnt += mp[sum-k];
            }
            
            mp[sum]++;
        }
        
        return cnt;
    }
};