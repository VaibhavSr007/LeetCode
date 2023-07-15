class Solution {
public:
    int solve(int idx, int prev, vector<vector<int>>& nums, int k, map<string,int>& dp){
        if(idx == nums.size() || k == 0){
            return 0;
        }
        
        
        
        string s = "";
        if(prev != -1){
            s = to_string(idx) + "=" + to_string(prev) + "=" + to_string(k);
            if(dp.find(s) != dp.end()){
                return dp[s];
            }
        }
        
        // if(dp[idx][k] != -1){
        //     return dp[idx][k];
        // }
        
        int ans;
        if(prev == -1 || nums[prev][1] < nums[idx][0]){
            int pick = nums[idx][2] + solve(idx+1, idx, nums, k-1, dp);
            int npick = solve(idx+1, prev, nums, k, dp);
            // cout<<pick<<":"<<npick<<" ";
            ans = max(pick,npick);
        }
        else{
            ans = solve(idx+1, prev, nums, k, dp);
        }
        
        if(prev != -1){
            dp[s] = ans;
        }
        
        return ans;
        
    }
    int maxValue(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(k+1,-1));
        map<string,int> dp;
        sort(nums.begin(), nums.end());
        return solve(0 , -1, nums, k, dp);
    }
};