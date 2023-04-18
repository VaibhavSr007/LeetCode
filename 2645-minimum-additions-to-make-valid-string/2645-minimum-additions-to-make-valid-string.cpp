class Solution {
public:
    int addMinimum(string word) {
        string res = "abc";
        int j=0;
        int i=0, ans=0; 
        while(i<word.length()){
            if(res[j] == word[i]){
                j++;
                i++;
                if(j>=3){
                    j = j%3;
                }
            }
            else{
                ans++;
                j++;
                if(j>=3){
                    j = j%3;
                }
            }
        }
        
        if(j!=0)
            ans += 3-j;
        return ans;
    }
};