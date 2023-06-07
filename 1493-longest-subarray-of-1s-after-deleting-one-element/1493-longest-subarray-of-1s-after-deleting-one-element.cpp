class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0, ans = 0;
        bool chk = true;
        
        while(j < nums.size()){
            if(nums[j] != 1 && chk){
                chk = false;
                j++;
            }
            else if(nums[j] != 1 && !chk){
                while(!chk){
                    if(nums[i] != 1){
                        chk = true;
                    }
                    i++;
                }
            }
            else{
                j++;
            }
            
            ans = max(ans,j-i);
        }
        return ans-1;
    }
};