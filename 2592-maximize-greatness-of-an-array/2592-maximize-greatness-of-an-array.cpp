class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0,i=0,j=0;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]==nums[i]){
                j++;
            }
            else{
                i++;
                j++;
                ans++;
            }
        }
        
        return ans;
    }
};