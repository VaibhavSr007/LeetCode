class Solution {
public:
    
//     void solve(vector<int> &nums, vector<int> &ans, vector<int> &op, int n, int idx, int &sum, int &res){
//         if(idx >= nums.size()){
//             if(op.size() == n){
//                 if(res < sum){
//                     res = sum;
//                     ans = op;
//                 }
//             }
//             return ;
//         }

//         solve(nums, ans, op, n, idx+1, sum, res);
        
//         sum += nums[idx];
//         op.push_back(nums[idx]);
//         solve(nums, ans, op, n, idx+1, sum, res);
//         sum -= nums[idx];
//         op.pop_back();
//     }
    
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1] > b[1]){
            return false;
        }
        return true;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // int idx = 0;
        // int sum = 0, res = INT_MIN;                      
        // vector<int> ans, op;                               // Recursive approach
        // solve(nums, ans, op, k, idx, sum, res);
        // return ans;
        
        vector<int> ans;
        vector<vector<int>> v, res;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        for(int i=v.size()-k; i<v.size(); i++){
            res.push_back(v[i]);
        }
        
        sort(res.begin(), res.end(), cmp);
        for(auto i:res){
            ans.push_back(i[0]);
        }
        return ans;
    }
};