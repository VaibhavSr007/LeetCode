class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int &len, vector<vector<int>> &dp){
        
        if(i == nums1.size() | j == nums2.size()){
            return  0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        solve(i+1, j, nums1, nums2, len, dp);  // recursive calls to reach all i, j combinations
        solve(i, j+1, nums1, nums2, len, dp);
        
        int ans = 0;
        if(nums1[i] == nums2[j]){ // if found equal add 1 and call for next iteration if i, j
            ans = 1 + solve(i+1, j+1, nums1, nums2, len, dp);
        }
        len = max(ans, len); // keep track of max len got ;
        
        return dp[i][j] = ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int maxLen = 0;
        solve(0, 0, nums1, nums2, maxLen, dp);
        return maxLen;
    }
};