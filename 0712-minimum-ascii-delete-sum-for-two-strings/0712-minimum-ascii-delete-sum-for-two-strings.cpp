class Solution {
public:
    
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0){
            int sum = 0;
            for(int x=j; x>=0; x--){
                sum += int(s2[x]);
            }
            return sum;
        }
        if(j<0){
            int sum = 0;
            for(int x=i; x>=0; x--){
                sum += int(s1[x]);
            }
            return sum;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans;
        if(s1[i] == s2[j]){
            ans = solve(i-1, j-1, s1, s2, dp);
        }
        else{
            int del1 = int(s1[i]) + solve(i-1, j, s1, s2, dp);
            int del2 = int(s2[j]) + solve(i, j-1, s1, s2, dp);
            
            ans = min(del1, del2);
        }
        
        
        return dp[i][j] = ans;
    }
    
    
    int minimumDeleteSum(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};