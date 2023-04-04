class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e = nums.size()-1;
        int m = s + (e-s)/2;
        int ans = -1;
        for(int i=0; s<=e; i++){
           if(nums[m]==target){
               ans = m;
               break;
           }
            else if(nums[m]<target){
                s = m+1;
            }
            else{
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
};