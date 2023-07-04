class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPallindrome(string s, int i, int j){
        
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int idx, string s, vector<string> op){
        if(idx == s.length()){
            ans.push_back(op);
            return ;
        }
        
        for(int i=idx; i<s.length(); i++){
            if(isPallindrome(s, idx, i)){
                string temp = s.substr(idx, i-idx+1);
                op.push_back(temp);
                solve(i+1, s, op);
                op.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> op;
        solve(0, s, op);
        return ans;
    }
};