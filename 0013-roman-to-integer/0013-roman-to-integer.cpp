class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> mp;
        mp['I'] = 1;  mp['V'] = 5;  mp['X'] = 10;  mp['L'] = 50;  mp['C'] = 100; mp['D'] = 500;  mp['M'] = 1000;   
        
        char back = s.back();
        int ans = mp[back];
        
        for(int i=s.length()-2; i>=0; i--){
            if(mp[s[i]] >= mp[back] ){
                back = s[i];
                ans += mp[back];
            }
            else{
                ans -= mp[s[i]];
            }
        }
        
        return ans;
    }
};