class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int cnt = 0;
        map<int,int> mp;
        for(auto i:nums1){
            for(auto j:nums2){
                mp[i+j]++;
            }
        }
        
        for(auto i:nums3){
            for(auto j:nums4){
                cnt += mp[-(i+j)];
            }
        }
        
        return cnt;
    }
};