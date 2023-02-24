class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int maxi = 0;
        int ans = 0;
        for(int i=0; i<nums.size()-1; i++){
            int st = nums[i];
            while(i<n-1 && nums[i]<=nums[i+1]){
                maxi = max(maxi,nums[i+1]-st);
                i++;
            }
            if(i<n-1 && nums[i]>nums[i+1]){
                ans += maxi;
                maxi = 0;
            }
            if(i==n-1){
                ans+=maxi;
            }
            // i--;
        }
        return ans;
    }
};