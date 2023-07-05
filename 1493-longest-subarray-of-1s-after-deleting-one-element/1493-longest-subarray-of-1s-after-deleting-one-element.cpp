class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int cnt = 0,  i=0,  j=0, ans=0;
        
        while(j<nums.size()){
            
            if(nums[j] == 0){
                cnt++;
            }
            
            j++;
            while(cnt >= 2){
                if(nums[i]==0){
                    cnt--;
                }
                i++;
            }
            
            ans = max(ans, j-i-1);
            
        }
        
        return ans;
    }
};