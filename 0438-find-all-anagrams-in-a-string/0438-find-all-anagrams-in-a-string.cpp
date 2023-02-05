class Solution {
public:
    bool chk(map<char,int> & mp){
        for(auto i:mp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> mp;
        for(auto i:p){
            mp[i]++;
        }
        
        for(int i=0; i<p.length(); i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
            }
        }
        if(chk(mp)){
            ans.push_back(0);
        }
        
        
        int i=0;
        int j=p.length();
        while(j<s.length()){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
            }
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
            }
            if(chk(mp)){
                ans.push_back(i+1);
            }
            i++;
            j++;
        }
        return ans;
    }
};