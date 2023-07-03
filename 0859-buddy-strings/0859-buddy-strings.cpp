class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        
        map<char,int> mp;
        
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:goal){
            mp[i]--;
        }
        for(auto i:mp){
            if(i.second != 0){
                return false;
            }
        }
        
        
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(goal[i] != s[i]){
                cnt++;
            }
            
            if(cnt > 2){
                break;
            }
        }
        
        if(cnt > 2 || cnt==1){
            return false;
        }
        
        mp.clear();
        if(cnt == 0){
            for(auto i:s){
                if(mp.find(i) != mp.end()){
                    return true;
                }
                mp[i]++;
            }
            return false;
        }
        
        return true;
        
    }
};