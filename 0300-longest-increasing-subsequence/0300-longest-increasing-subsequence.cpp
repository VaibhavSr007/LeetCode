class Solution {
public:
    vector<vector<int>> v;
    int solve(vector<int>& nums, int i, int prev){
        if(i==nums.size()){
            return 0;
        }
        
        if(prev != -1 && v[i][prev] != -1){
            return v[i][prev];
        }
        
        int res;
        if(prev == -1 || nums[i] > nums[prev]){
            int take = 1 + solve(nums, i+1, i);
            int no_take = solve(nums, i+1, prev);
            res = max(no_take,take);
        }
        else{
            res = solve(nums, i+1, prev);
        }
        
        if(prev != -1)
            v[i][prev] = res;
        
        return res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        v.resize(n+1, vector<int>(n+1,-1));
        return solve(nums, 0 , -1);
    }
};