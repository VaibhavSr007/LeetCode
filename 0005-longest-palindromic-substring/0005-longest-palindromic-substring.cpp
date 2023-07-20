class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length() == 1){
            return s;
        }
        
        string ans = "";
        for(int i=0; i<s.length()-1; i++){
            int left = i; 
            int right = i+1;
            int cnt = 0;
            if(s[left] == s[right]){
                while(left >=0 && right < s.length() && s[left] == s[right]){
                    left--;
                    right++;
                }
                left++;
            }
            right--;
            if(ans.length() < right-left+1)
                ans = s.substr(left, right-left+1);
        }
        
        for(int i=1; i<s.length()-1; i++){
            int left = i-1; 
            int right = i+1;
            if(s[left] == s[right]){
                while(left >=0 && right < s.length() && s[left] == s[right]){
                    left--;
                    right++;
                }
                
            }
            left++;
            right--;
            if(ans.length() < right-left+1)
                ans = s.substr(left, right-left+1);
            
        }
        
        return ans;
    }
};