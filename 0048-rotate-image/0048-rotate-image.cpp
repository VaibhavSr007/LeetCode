class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> copy(nums);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                 nums[i][j] = copy[n-j-1][i];
            }
        }
        
    }
};