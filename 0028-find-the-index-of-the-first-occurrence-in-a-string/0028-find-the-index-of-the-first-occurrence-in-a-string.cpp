class Solution {
public:
    int strStr(string hay, string ned) {
        if(hay.find(ned) != string::npos){
            return hay.find(ned);
        }
        return -1;
        
        
//         if(hay.length() < ned.length()){
//             return -1;
//         }
        
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
    }
};