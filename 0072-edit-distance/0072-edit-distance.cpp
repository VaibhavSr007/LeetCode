class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans;
        if(s1[i] == s2[j]){
            ans = solve(i-1, j-1, s1, s2, dp); 
        }
        else{
            int del = 1 + solve(i-1, j,  s1, s2, dp);
            int add = 1 + solve(i, j-1, s1, s2, dp);
            int rep = 1 + solve(i-1, j-1, s1, s2, dp);
            ans = min(del,min(add,rep));
        }
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};