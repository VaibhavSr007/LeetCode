class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;
        int n = k, len = 0, ans = INT_MIN;
        while(j < nums.size()){
            if(nums[j] == 0 && n > 0){
                n--;
                j++;
            }
            else if(nums[j] == 0 && n <= 0){
                while(n <= 0){
                    if(nums[i] == 0){
                        n++;
                    }
                    i++;
                }
            }
            else{
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};