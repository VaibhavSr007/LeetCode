class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, pre=1;
        
        for(auto i:nums){
            pre = i*pre;
            ans = max(ans,pre);
            if(pre == 0){
                pre = 1;
            }
        }
        pre = 1;
        for(int i=nums.size()-1; i>=0; i--){
            pre = nums[i]*pre;
            ans = max(ans,pre);
            if(pre == 0){
                pre = 1;
            }
        }
        
        return ans;
    }
};