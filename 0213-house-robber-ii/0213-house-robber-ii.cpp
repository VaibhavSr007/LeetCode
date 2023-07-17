class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        
        int ans;
        if(prev == -1 || prev != idx-1){
            int pick = nums[idx] + solve(idx+1, idx, nums, dp);
            int npick = solve(idx+1, prev, nums, dp);
            ans = max(pick, npick);
        }
        else{
            ans = solve(idx+1, prev, nums, dp);
        }
        
        if(prev != -1){
            dp[idx][prev] = ans;
        }
        
        return ans;
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        vector<int> nums1 = nums;
        vector<int> nums2 = nums;
        nums1.pop_back();
        nums2.erase(nums2.begin());

        vector<vector<int>> dp1(100, vector<int>(100, -1));
        vector<vector<int>> dp2(100, vector<int>(100, -1));
        return max(solve(0, -1, nums1, dp1), solve(0, -1, nums2, dp2));
    }
};