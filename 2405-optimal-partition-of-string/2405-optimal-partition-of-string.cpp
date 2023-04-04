class Solution {
public:
    int partitionString(string s) {
//         int count = 0;
//         string ans = "";
//             for(int j=0; j<s.length(); j++){
//                 if(ans.find(s[j]) == string::npos){
//                     ans.push_back(s[j]);
//                 }
//                 else if(ans.find(s[j]) != string::npos){
//                     count++;
//                     ans = s[j];
//                 }
//                 cout<<ans<<" ";
//             }
        
//         return ++count;
        int cnt = 0;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            if(ans.find(s[i]) == string::npos){
                ans.push_back(s[i]);
            }
            else{
                cnt++;
                ans = s[i];
            }
        }
        cnt++;
        return cnt;
    }
};