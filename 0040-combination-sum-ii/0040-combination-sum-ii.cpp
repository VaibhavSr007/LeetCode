class Solution {
public:
    void solve(set<vector<int>> &ans, vector<int> &nums, vector<int> &op, int &sum, int target, int idx){
        if(sum > target){
            return ;
        }
        if(sum == target){
            ans.insert(op);
            return ;
        }
        
        if(idx >= nums.size()){
            return;
        }
        
        
        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i-1] == nums[i]){
                continue;
            }
            sum += nums[i];
            op.push_back(nums[i]);
            solve(ans, nums, op, sum, target, i+1);
            sum -= nums[i];
            op.pop_back();
            
        }
        
        // solve(ans, nums, op, sum, target, idx+1);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> op;
        set<vector<int>> ans;
        int idx = 0;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, op, sum, target, idx);
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};