class Solution {
public:
    map<string, int> mp;
    int solve(int idx, int prev, int diff, vector<int>& nums){
        if(idx == nums.size()){
            return 0;
        }
        
        string s = to_string(idx) + "=" +  to_string(prev);
        if(mp.find(s) != mp.end()){
            return mp[s];
        }
        
        int ans;
        if(prev == -1 || nums[idx] - nums[prev] == diff){
            int pick = 1 + solve(idx+1, idx, diff, nums);
            int npick = solve(idx+1, prev, diff, nums);
            ans = max(pick, npick);
        }
        else{
            ans = solve(idx+1, prev, diff, nums);
        }
        
        return mp[s] = ans;
    }
    
    int longestSubsequence(vector<int>& arr, int diff) {
        
        // return solve(0, -1, difference, arr);   // memoized code gives TLE
        
        // Tabulated
        map<int, int> mp;
        int ans=  0;
        
        for(auto i:arr){
            
            int prev_len = 0;
            if(mp.find(i-diff) != mp.end()){
                prev_len = mp[i-diff];
            }
            
            mp[i] = 1 + prev_len;
            ans = max(ans, mp[i]);
        }
        
        return ans;
    }
};