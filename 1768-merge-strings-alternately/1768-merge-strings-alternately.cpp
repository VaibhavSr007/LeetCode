class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        bool chk = true;
        int i = 0, j=0;
        while(i<w1.length() && j<w2.length()){
           if(chk){
               ans.push_back(w1[i]);
               i++;
               chk = !chk;
           }
            else{
               ans.push_back(w2[j]);
               j++;
               chk = !chk;
            }
        }
        
        while(i < w1.length()){
            ans.push_back(w1[i]);
            i++;
        }
        while(j < w2.length()){
            ans.push_back(w2[j]);
            j++;
        }
        return ans;
    }
};