class Solution {
public:
    void solve(int idx, vector<int> &nums, int k, vector<int> &res, int & ans){
        if(idx == nums.size()){
            int maxi = INT_MIN;
            for(int x=0; x<k; x++){
                maxi = max(res[x], maxi);
            }
            
            ans = min(ans, maxi);
            return ;
        }
        
        for(int i=0; i<k; i++){
            res[i] += nums[idx];
            solve(idx+1, nums, k , res, ans);
            res[i] -= nums[idx];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> res(k,0);
        solve(0, cookies, k, res, ans);
        return ans;
    }
};