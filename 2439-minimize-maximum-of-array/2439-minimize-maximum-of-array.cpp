class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int mini = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int val = ceil(double(sum)/(i+1));
            mini = max(val,mini);
        }
        
        return mini;
    }
};