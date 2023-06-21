class Solution {
public:
    bool solve(int idx, vector<int>& arr, vector<int>& dp){
        if(idx < 0 || idx >= arr.size()){
            return false;
        }
        
        if(arr[idx] == 0){
            return true;
        }
        if(dp[idx] == -2){
            return false;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        dp[idx] = -2;
        bool left = solve(idx+arr[idx], arr, dp);
        bool right = solve(idx-arr[idx], arr, dp);
        
        if(left || right){
            return dp[idx] = 1;
        }
        
        return dp[idx] = 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(start, arr, dp);
    }
};