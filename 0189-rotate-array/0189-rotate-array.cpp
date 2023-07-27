class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> copy(nums);
        for(int i=0; i<nums.size(); i++){
            nums[(i+k)%n] = copy[i];
        }
    }
};