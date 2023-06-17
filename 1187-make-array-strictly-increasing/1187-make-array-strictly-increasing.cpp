class Solution {
public:
    
    vector<map<int,int>> dp;
    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2){
        if(i == arr1.size()){
            return 0;
        }
        
        if(dp[i].find(prev) != dp[i].end()){
            return dp[i][prev];
        }
        
        int take = 1e9, no_take = 1e9;
        if(arr1[i] > prev){
            no_take = solve(i+1,arr1[i], arr1, arr2);
        }
        
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(idx < arr2.size()){
            take = 1 + solve(i+1,arr2[idx],arr1,arr2);
        }
        
        dp[i][prev] = min(take,no_take);
        return min(take,no_take);
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int i=0, prev=-1, ans = 0 ;
        dp.resize(2001);
        ans = solve(i, prev, arr1, arr2);
        
        if(ans==1e9){
            return -1;
        }
        
        return ans;
    }
};