class Solution {
public:
    
    int ans = 0;
    void solve(int idx, vector<int> v, vector<vector<int>> &nums, int cnt){
        
        if(idx == nums.size()){
            bool chk = true;
            for(auto i:v){
                if(i!=0){
                    chk = false;
                    break;
                }
            }
            
            if(chk){
                ans = max(ans,cnt);
            }
            return ;
        }
        
        v[nums[idx][0]] -= 1;
        v[nums[idx][1]] += 1;
        solve(idx+1, v, nums, cnt+1);
        v[nums[idx][0]] += 1;
        v[nums[idx][1]] -= 1;
        
        solve(idx+1, v, nums, cnt);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int cnt = 0;
        vector<int> v(n,0);
        solve(0, v, requests, cnt);
        return ans;
    }
};