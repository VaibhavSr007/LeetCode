class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=2){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return  dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        
        
//         vector<int> v;
//         v.push_back(1);
//         v.push_back(1);
//         int ans = 0;
//         if(n<2){
//             return 1;
//         }                                // simple fibonacci series approach
        
//         for(int i=2; i<n+1; i++){
//             ans = v[i-1] + v[i-2];
//             v.push_back(ans);
//         }
//         return v[n];
    }
};