class Solution {
public:
//     void solve(vector<int>& nums, set<vector<int>>& s, vector<int> op, int idx){
//         if(idx>=nums.size()){
//             s.insert(op);
//             return ;
//         }
        
//         solve(nums,s,op,idx+1);
        
//         op.push_back(nums[idx]);
//         solve(nums,s,op,idx+1);
//         op.pop_back();
//     }
    
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> op, int idx){

        ans.push_back(op);
        
//         if(idx>=nums.size()){   not needed as loop will itself end whn idx >= nums.size()
//             return ;
//         }
        
        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            op.push_back(nums[i]);
            solve(nums,ans,op,i+1);
            op.pop_back();
            
        }
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> op;
        int idx = 0;
        
        solve(nums,ans,op,idx);
        
        // for(auto i:s){
        //     ans.push_back(i);
        // }
        return ans;
    }
};