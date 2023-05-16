class Solution {
public:
    
    void solve(vector<int> op, vector<int> nums, vector<vector<int>> &ans,int idx){
        if(idx >= nums.size()){  // base case
            ans.push_back(op);
            return ;
        }
        
        solve(op,nums,ans,idx+1);  // exclude
        op.push_back(nums[idx]);   // include
        solve(op,nums,ans,idx+1);  // thn call
        op.pop_back();
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(op, nums,ans,0);
        
        return ans;
        
        
    
    }
};