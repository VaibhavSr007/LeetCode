class Solution {
public:
    bool solve(int idx, string s, set<string> st, map<int, bool> &mp){
        
        if(idx == s.length()){
            return true;
        }
        
        if(mp.find(idx) != mp.end()){
            return mp[idx];
        }
        for(int i=idx; i<s.length(); i++){
            string temp = s.substr(idx, i-idx+1);
            if(st.find(temp) != st.end()){
                if(solve(i+1, s, st, mp)){
                    return true;
                }
            }
        }
        
        
        return mp[idx] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        map<int, bool> mp;
        for(auto i:wordDict){
            st.insert(i);
        }
        
        return solve(0, s, st, mp);
    }
};