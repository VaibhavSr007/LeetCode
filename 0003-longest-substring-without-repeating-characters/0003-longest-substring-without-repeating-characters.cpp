class Solution {
public:
    int max(int x, int y){
        if(x < y){
            return y;
        }
        return x;
    }
    int lengthOfLongestSubstring(string s) {
//         string ans = "";
//         int max_len = 0;
//         for(int j=0; j<s.length(); j++){
//             ans = "";
//             for(int i=j; i<s.length(); i++){
//                 if(ans.find(s[i]) == string::npos){
//                     ans.push_back(s[i]);
//                 }
//                 else if(ans.find(s[i]) != string::npos){
//                     break;
//                 }
//             }
//             if(max_len<ans.length()){
//                 max_len = ans.length();
//             }
//         }
        
//         return max_len;
        
        
//         int len = 0;
//         int l = 0;
//         int r = 0;
//         map<char,int> mp;
        
//         while(r<s.length()){
//             if(mp.find(s[r]) != mp.end()){
//                 l = max(l, mp[s[r]]+1);
//             }
            
//             mp[s[r]] = r;
//             len  = max(len, r-l+1);
//             r++;
//         }
//         return len;
        
        if(s.length()==0){return 0;}
        int ans = 1;
        map<char,int> mp;
        int i=0, st = 0;
        while(i<s.length()){
            if(mp.find(s[i]) != mp.end()){
                st = max(st,mp[s[i]]+1);
            }
            ans = max(ans, i-st+1);
            mp[s[i]] = i;
            i++;
        }
        return ans;
    }
};