class Solution {
public:
    void solve(int k, int n, set<vector<int>> & ans, vector<int> op,int idx, int sum){
        
        if(sum > n){
            return ;
        }
        
        if(op.size()==k){
            if(sum==n){
                ans.insert(op);
            }
            return ;
        }
        
        for(int i=idx; i<=9; i++){
            op.push_back(i);
            sum += i;
            solve(k,n,ans,op,i+1,sum);
            sum -= i;
            op.pop_back();
            solve(k,n,ans,op,i+1,sum);
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> op;
        int idx = 1, sum=0;
        solve(k,n,ans,op,idx,sum);
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    } 
};