class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &op, vector<int> &nums, int target, int &sum, int idx){
        if(sum > target){
            return ;
        }
        
        if(idx >= nums.size()){
            if(sum == target){
                ans.push_back(op);
                // return ;
            }
            return ;
        }
        
        sum += nums[idx];
        op.push_back(nums[idx]);
        solve(ans,op,nums,target,sum,idx);
        sum -= nums[idx];
        op.pop_back();
        
        solve(ans,op,nums,target,sum,idx+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int idx = 0, sum=0;
        solve(ans,op,candidates,target,sum,idx);
        return ans;
    }
};