class Solution {
public:
//     void solve(int i, int sum, vector<int> op, int n, vector<vector<int>> &ans){
//         if(i > 9){
//             if(sum == 0 && n==op.size()){
//                 ans.push_back(op);
//             }
//             return ;
//         }
        
//         op.push_back(i);
//         solve(i+1, sum - i, op, n, ans);
//         op.pop_back();
//         solve(i+1, sum, op, n, ans);
        
//     }
    
    vector<vector<int>> ans;
    void solve(int idx, int cnt, int sum, vector<int> op){
        
        
        
        if(sum == 0 && op.size() == cnt){
            ans.push_back(op);
            return ;
        }
        
        if(idx > 9 || sum < 0 || op.size() > cnt){
            return ;
        }
        
        solve(idx+1, cnt, sum, op);
        op.push_back(idx);
        solve(idx+1, cnt, sum-idx, op);
        op.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<vector<int>> ans;
        // solve(1, n, {}, k, ans);
        solve(1, k, n, {});
        return ans;
    }
};