class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            set<int> pre, pos;
            
            for(int j=0; j<=i; j++){
                pre.insert(nums[j]);
            }
                
            for(int j=i+1; j<nums.size(); j++){
                pos.insert(nums[j]);
            }
            ans.push_back(pre.size()-pos.size());
        }
        
        return ans;
    }
};