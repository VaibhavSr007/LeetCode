class Solution {
public:
    void solve(vector<string> &ans, string s, string op, int idx){
        if(idx >= s.length()){
            if(op.length() == s.length())
                ans.push_back(op);
            return ;
        }
        
        solve(ans, s, op, idx+1);
        
        if(s[idx] >= 'a' && s[idx] <= 'z'){
            op.push_back(s[idx]);
            solve(ans, s, op, idx+1);
            op.pop_back();
            
            s[idx] = char(int(s[idx]) - 32);
            op.push_back(s[idx]);
            solve(ans, s, op, idx+1);
            op.pop_back();
            s[idx] = char(int(s[idx]) + 32);
        }
        else if(s[idx] >= 'A' && s[idx] <= 'Z'){
            op.push_back(s[idx]);
            solve(ans, s, op, idx+1);
            op.pop_back();
            
            s[idx] = char(int(s[idx]) + 32);
            op.push_back(s[idx]);
            solve(ans, s, op, idx+1);
            op.pop_back();
            s[idx] = char(int(s[idx]) - 32);
        }
        else{
            op.push_back(s[idx]);
            solve(ans, s, op, idx+1);
            op.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string op;
        int idx = 0;
        solve(ans, s, op, idx);
        return ans;
    }
};