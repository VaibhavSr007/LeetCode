class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v,v1;
        v1.push_back(nums.back());
        v.push_back(nums[0]);
        int ans1= 0, ans2=0;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i][0] < v.back()[1]){
                ans1++;
            }
            else{
                v.push_back(nums[i]);
            }
        }
        
        
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i][1] > v1.back()[0]){
                ans2++;
            }
            else{
                v1.push_back(nums[i]);
            }
        }
        
        return min(ans2,ans1);
    }
};