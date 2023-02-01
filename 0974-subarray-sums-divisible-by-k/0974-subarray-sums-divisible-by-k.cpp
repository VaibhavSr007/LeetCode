class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int cnt = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j=i; j<nums.size(); j++){ // brute force
        //         sum += nums[j];
        //         if(sum%k==0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
        // int sum = 0;
        // vector<int> pre(k,0); // to keep the prefix sum of all vals less than k's cnt
        // pre[sum]++; // at start sum is 0 so its cnt is increased to 1
        // int ans = 0;
        // for(auto i:nums){
        //     sum = (sum + i)%k;
        //     if(sum < 0){ // for handling the negative case
        //         sum += k;
        //     }
        //     ans += pre[sum];
        //     pre[sum]++;
        // }
        // return ans;
        
        int ans = 0;
        int sum = 0;
        map<int,int> mp;
        for(int i=0; i<k; i++){
            mp[i] = 0;
        }
        mp[sum]++;
        for(auto i:nums){
            sum = (sum+i)%k;
            if(sum<0){ sum+=k; }
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};                                                                                                    