class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        int mini = INT_MAX, pro = 0;
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            pro = max(pro, nums[i]-mini);
        }
        
        return pro;
    }
};