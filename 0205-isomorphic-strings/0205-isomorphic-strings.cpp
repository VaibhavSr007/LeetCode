class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp, mp1;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }
        
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = t[i];
            }
            else{
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }
        
        for(int i=0; i<t.length(); i++){
            if(mp1.find(t[i]) == mp1.end()){
                mp1[t[i]] = s[i];
            }
            else{
                if(mp1[t[i]] != s[i]){
                    return false;
                }
            }
        }
        
        return true;

    }
};