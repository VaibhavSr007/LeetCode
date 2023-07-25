class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, m = s + (e-s)/2;
        
        while(s<e){
            if(nums[m] >= nums[e]){
                s = m+1;
            }
            else{
                e = m;
            }
            m = s + (e-s)/2;
        }
        
        return nums[s];
    }
};