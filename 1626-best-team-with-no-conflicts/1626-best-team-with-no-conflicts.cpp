class Solution {
public:
    
    int solve(int idx, int prev, vector<vector<int>> &nums, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            return 0;
        }
        
        
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        
        int ans;
        if(prev == -1 || nums[idx][1] >= nums[prev][1]){
            int pick = nums[idx][1] + solve(idx+1, idx, nums, dp);
            int npick = solve(idx+1, prev, nums, dp);
            ans = max(npick, pick);
        }
        else{
            ans = solve(idx+1, prev, nums, dp);
        }
        
        if(prev!= -1){
            dp[idx][prev] = ans;
        }
        
        return ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> v, dp(n, vector<int> (n,-1));
        for(int i=0; i<scores.size(); i++){
            v.push_back({ages[i],scores[i]});
        }
        
        sort(v.begin(), v.end());
        
        return solve(0, -1, v, dp);
    }
};