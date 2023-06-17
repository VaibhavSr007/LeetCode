class Solution {
public:
    void solve(vector<int>& nums, int i, int ans, int &cnt, int maxi){
        if(i==nums.size()){
            if(maxi == ans){
                cnt++;
            }
            return ;
        }
        
        solve(nums, i+1, ans, cnt, maxi);
        solve(nums, i+1, ans | nums[i], cnt, maxi);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int ans = 0, cnt = 0;
        for(auto i:nums){
            ans |= i;
        }
    
        solve(nums,0,0,cnt,ans);
        
        return cnt;
    }
};