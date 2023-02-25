class Solution {
public:
    int solve(int n, vector<int>& dp, vector<int>& nums){
        if(n==0){
            return nums[n];
        }
        if(n < 0){
           return 0; 
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = nums[n] + solve(n-2,dp,nums);
        int nopick = solve(n-1,dp,nums);
        
        dp[n] = max(nopick,pick);
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()<=3){
            int ans = *max_element(nums.begin(),nums.end());
            return ans;
        }
        int n = nums.size()-2;
        vector<int> dp1(n+1,-1); // for maximum loot leaving last element
        int last = nums[nums.size()-1];
        nums.pop_back();
        int without_last = solve(n,dp1,nums);
        
        vector<int> dp2(n+1,-1); // for maximum loot leaving last element
        int first = nums[0];
        nums.erase(nums.begin());
        nums.push_back(last);
        int without_first = solve(n,dp2,nums);
        
        return max(without_first,without_last);
    }
};