class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& s, vector<int> op, int idx){
        if(idx>=nums.size()){
            s.insert(op);
            return ;
        }
        
        solve(nums,s,op,idx+1);
        
        op.push_back(nums[idx]);
        solve(nums,s,op,idx+1);
        op.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> op;
        int idx = 0;
        
        solve(nums,s,op,idx);
        
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};