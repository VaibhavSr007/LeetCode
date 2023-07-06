class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int i=0, j=0, sum=0, ans=-1, target = 0;
        
        
        for(auto a:nums){
            target += a;
        }
        
        target -= x;
        
        if(target < 0){
            return -1;
        }
        
        while(j < nums.size()){
            
            sum += nums[j];
            j++;
            
            while(sum > target){
                sum -= nums[i];
                i++;
            }
            
            if(sum == target){
                ans = max(ans, j-i);
            }
        }
        
        
        return ans == -1 ? -1 : nums.size()-ans;
    }
};