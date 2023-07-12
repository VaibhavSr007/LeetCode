class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0){
            return 0;
        }
        int i=0, j=0, cnt =0, pro = 1, n = nums.size();
        
        while(j < n){
            pro *= nums[j];
            j++;
            while(pro >= k){
                pro /= nums[i];
                i++;
                if(i > j){
                    return 0;
                }
            }
            cnt += j-i;
            
        }
        
        return cnt;
    }
};