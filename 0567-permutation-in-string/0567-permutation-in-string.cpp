class Solution {
public:
    
    bool chk(map<char, int> mp){
        for(auto i:mp){
            if(i.second != 0){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string p, string s) {
        if(p.size() > s.size()){
           return false;
       } 
        
        vector<int> ans;
        map<char, int> mp;
        for(auto i:p){
            mp[i]++;
        }
        
        
        for(int i=0; i<p.length(); i++){
            mp[s[i]]--;
        }
        
        
        
        int i=0, j=p.length();
        while(j < s.length()){
            
            if(chk(mp)){
                return true;
            }
            mp[s[i++]]++;
            mp[s[j++]]--;
        }
        
        if(chk(mp)){
            return true;
        }
        
        return false;
    }
};