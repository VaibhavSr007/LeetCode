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
    
    vector<int> findAnagrams(string s, string p) {
       if(p.size() > s.size()){
           return {};
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
                ans.push_back(i);
            }
            mp[s[i++]]++;
            mp[s[j++]]--;
        }
        
        if(chk(mp)){
            ans.push_back(i);
        }
        
        return ans;
    }
};