class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        
        int j = 0;
        ans = max(ans,sum/k);
        for(int i=k; i<nums.size(); i++){
            sum -= nums[j++];
            sum += nums[i];
            ans = max(ans,sum/k);
        }
        return ans;
    }
};