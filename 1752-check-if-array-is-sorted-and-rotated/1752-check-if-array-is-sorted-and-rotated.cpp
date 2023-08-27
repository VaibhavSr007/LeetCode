class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 1, n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > nums[(i+1)%n]){
                cnt--;
            }
            
            if(cnt < 0){
                return false;
            }
        }
        
       return true;
    }
};