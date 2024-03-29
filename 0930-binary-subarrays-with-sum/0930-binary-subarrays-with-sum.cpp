class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int,int> mp;
        int ans = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == goal){
                ans++;
            }
            
            if(mp.find(sum-goal) != mp.end()){
                ans += mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};