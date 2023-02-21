class Solution {
public:
    // void solve(vector<string>& v, string op, int idx, string kp[], string digits){
    //     if(idx>=digits.length()){
    //         v.push_back(op);
    //         return ;
    //     }
    //     int kp_idx = digits[idx]-'0';
    //     string x = kp[kp_idx];
    //     for(int i=0; i<x.length(); i++){
    //         op.push_back(x[i]);
    //         solve(v,op,idx+1,kp,digits);
    //         op.pop_back();
    //     }
    // }
    
    void solve(string& s, vector<string>& ans, string op, int idx, vector<string>& kp){
        if(idx>=s.length()){
            ans.push_back(op);
            return ;
        }
        // int d = int(s[idx]-'0'); 
        string x = kp[int(s[idx]-'0')];
        for(int i=0; i<x.length(); i++){
            op.push_back(x[i]);
            solve(s,ans,op,idx+1,kp);
            op.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // vector<string> v;
        // string op = "";
        // int idx  = 0;
        // if(digits.length()<1){
        //     return v;
        // }
        // string kp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // solve(v,op,idx,kp,digits);
        // return v;
        
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string op = "";
        int idx = 0;
        vector<string> kp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,op,idx,kp);
        return ans;
    }
};