class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(int i=0; i<word.length(); i++){
            if(word[i]>=65 && word[i]<=90){
                cnt1++;
            }
            else if(word[i]>=97 && word[i]<=122){
                cnt2++;
            }
        }
        
        if(word.length() == cnt1 || word.length() == cnt2){
            return true;
        }
        else if(cnt1 == 1 && word[0]>=65 && word[0]<=90){
            return true;
        }
        
        return false;
    }
};