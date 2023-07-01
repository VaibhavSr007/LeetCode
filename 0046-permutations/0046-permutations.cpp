class Solution {
public:
    void solve(vector<int> op, vector<vector<int>> &ans, set<int> &s, vector<int> &nums){
        if(op.size()==nums.size()){
            ans.push_back(op);
        }
        
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                op.push_back(nums[i]);
                s.insert(nums[i]);
                solve(op, ans, s, nums);
                s.erase(nums[i]);
                op.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> op;
        vector<vector<int>> ans;
        set<int> s;
        solve(op, ans, s, nums);
        return ans;
    }
};