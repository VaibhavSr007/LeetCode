class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> back = nums[0];
        int i=1, cnt = 0;
        
        
        
        while(i < nums.size()){
            if(back[1] > nums[i][0]){
                cnt++;
            }
            else{
                back = nums[i];
            }
            i++;
        }
        
        int x = 0;
        back = nums.back();
        i = nums.size()-2;
        while(i >= 0){
            if(back[0] < nums[i][1]){
                x++;
            }
            else{
                back = nums[i];
            }
            i--;
        }
        return min(cnt,x);
    }
};