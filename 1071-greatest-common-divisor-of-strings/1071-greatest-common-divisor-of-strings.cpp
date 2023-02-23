class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        string ans = "";
        int i=0;
        int j=0;
        
        while(i<str1.length() && j<str2.length()){
            if(str1[i]==str2[j]){
                ans.push_back(str1[i]);
            }
            else{
                break;
            }
            i++;
            j++;
        }
        if(ans.length()==0){ return ans;}
        while(str1.length()%ans.length()!=0 || str2.length()%ans.length()!=0){
            ans.pop_back();
        }
        
        int rep1 = str1.length()/ans.length();
        int rep2 = str2.length()/ans.length();
        string x = "", y="";
        for(int i=0; i<rep1; i++){
            x+=ans;
        }
        if(x!=str1){ return "";}
        for(int i=0; i<rep2; i++){
            y+=ans;
        }
        if(y!=str2){ return "";}
        return ans;
    }
};