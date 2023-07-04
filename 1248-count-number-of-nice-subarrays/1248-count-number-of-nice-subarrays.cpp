class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0, j=0, sum=0; 
        map<int,int> mp;
        while(j<nums.size()){
            
            sum += nums[j]%2;
            
            j++;
            if(sum == k){
                ans++;
            }
            
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            
            mp[sum]++;
        }
        
        return ans;
    }
};