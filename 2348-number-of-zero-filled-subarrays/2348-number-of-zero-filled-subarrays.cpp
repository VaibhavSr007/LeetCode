class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int i=0;
        long long ans = 0;
        while(i<nums.size()){
            if(nums[i]==0){
                int j=i;
                while(j<nums.size() && nums[j]==0){
                    ans = ans + (j-i) + 1;
                    j++;
                }
                i = j;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};