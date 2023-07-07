class Solution {
public:
    
    int solve(int i, int j, char target, string s, int cnt){
        int ans = 0;
        while(j < s.length()){
            if(s[j] != target){
                cnt--;
            }
            
            j++;
            while(cnt < 0){
                if(s[i] != target){
                    cnt++;
                }
                i++;
            }
            
            ans = max(ans, j-i);
        }
        
        return ans; 
    }
    
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int ans = 0;
        for(auto i:s){
            mp[i]++;
        }
        
        for(auto i:mp){
            ans = max(ans, solve(0,0,i.first,s,k));
        }
        
        return ans;
    }
};