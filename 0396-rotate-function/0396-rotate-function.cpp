class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int tot = 0, sum = 0, ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            tot += nums[i]*i;
            sum += nums[i];
        }
        // cout<<tot<<":"<<sum<<" ";
        int idx = nums.size()-1, n = nums.size()-1;
        while(idx >= 0){
            tot = tot - nums[idx]*n + sum - nums[idx];
            // cout<<tot<<" ";
            idx--;
            ans = max(ans, tot);
        }
        
        return ans;
    }
};