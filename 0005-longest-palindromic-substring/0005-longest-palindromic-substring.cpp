class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length() == 1){
            return s;
        }
        
        int maxlen = 0, start = 0;
        for(int i=0; i<s.length()-1; i++){
            int left = i; 
            int right = i+1;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            
            if(maxlen < right-left-1){
                maxlen = right-left-1;
                start = left +1;
            }
        }
        
        for(int i=0; i<s.length(); i++){
            int left = i; 
            int right = i;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            
            if(maxlen < right-left-1){
                maxlen = right-left-1;
                start = left +1;
            }
        }
        
        return s.substr(start, maxlen);
    }
};