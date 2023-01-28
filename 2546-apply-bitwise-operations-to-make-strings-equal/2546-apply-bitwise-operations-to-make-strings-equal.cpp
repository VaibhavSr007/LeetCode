class Solution {
public:
    bool chk(string s){
        for(auto i:s){
            if(i!='0'){
                return false;
            }
        }
        return true;
    }
    
    bool makeStringsEqual(string s, string target) {
        
//         if(chk(s) || chk(target)){
//             for(int i=0; i<s.length(); i++){
//                 if(s[i]!=target[i]){
//                     return false;
//                 }
//             }
//             return  true;

//         }
        
        if(chk(s)){
            if(chk(target)){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(chk(target)){
            return false;
        }
        
        return true;
    }
};