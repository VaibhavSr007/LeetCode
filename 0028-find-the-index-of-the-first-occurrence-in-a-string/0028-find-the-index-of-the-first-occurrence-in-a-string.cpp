class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(hay.find(ned) != string::npos){
        //     return hay.find(ned);      // optimized inbuild libraray approach
        // }
        // return -1;
        
        
        if(haystack.length() < needle.length()){
            return -1;
        }
        
//         int n = ned.length();
//         for(int i=0; i<hay.length()-n+1; i++){   // optized
            
//             if(hay[i] == ned[0]){
//                 bool x = true;
//                 int idx = i;
//                 for(auto j:ned){
//                     if(hay[idx++] != j){
//                         x = false;
//                     }
//                 }
                
//                 if(x==true){
//                     return i;
//                 }
//             }
//         }
        
//         return -1;
        
        int n= needle.length();
        int m= haystack.length();
        
        for(int i=0; i<m; i++){
            if(haystack[i]==needle[0]){
                int st = i, cnt = 0;
                bool chk = true;
                for(int j=0; j<n; j++){
                    if(needle[j]!=haystack[st]){
                        chk = false;
                        break;
                    }
                    else{
                        cnt++;
                    }
                    st++;
                }
                if(chk && cnt==n){
                    return i;
                }
            }
        }
        return -1;
    }
};