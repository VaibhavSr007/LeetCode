class Solution {
public:
    void solve(int open, int close, string op, vector<string> & ans, int n){
        if(close == n && open == n){
            ans.push_back(op);
        }
        
        if(open < n){
            op.push_back('(');
            solve(open+1, close, op, ans,n);
            op.pop_back();
        }
        
        if(close < open){
            op.push_back(')');
            solve(open, close+1, op, ans,n);
            op.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        // condition must to remember here that: 
        // i) in every valid string or going to be valid string open will be greater than or
        // equal to close but never greater
        vector<string> ans;
        solve(0, 0, "",ans,n);
        return ans;
    }
};