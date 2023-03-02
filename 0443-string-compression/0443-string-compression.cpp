class Solution {
public:
    int compress(vector<char>& s) {
//         int count = 1;
//         string ans;
        
//         for(int i=0; i<chars.size(); i++){
            
//             while(i<chars.size()-1 && chars[i]==chars[i+1]){
//                 count++;
//                 i++;
//             }
            
//             ans = ans + chars[i];
//             if(count==1){
//                 continue;
//             }
//             else{
//                 ans = ans + to_string(count);
//                 count = 1;
//             }
//         }
        
//         chars.clear();
        
//         for(int i=0; i<ans.length(); i++){
//             chars.push_back(ans[i]);
//         }
        
//         return chars.size();
        
//         int cnt = 1;
//         string ans = "";
//         for(int i=0; i<chars.size(); i++){
//             if(ans.length()==0){
//                 ans.push_back(chars[i]);
//             }
//             else if(ans.back()==chars[i]){
//                 cnt++;
//             }
//             else if(ans.back()!=chars[i]){
//                 if(cnt>1){
//                     ans += to_string(cnt);
//                 }
//                 ans.push_back(chars[i]);
//                 cnt = 1;
//             }
            
//         }
        
//         if(cnt>1){
//                ans += to_string(cnt);
//             }
//         cout<<ans<<endl;
//         chars.clear();
//         for(int i=0; i<ans.length(); i++){
//             chars.push_back(ans[i]);
//         }
//         return ans.size();
        
        string ans = "";
        int cnt = 1;
        for(int i=0; i<s.size(); i++){
            if(i==0){
                ans.push_back(s[i]);
            }
            else if(s[i]==ans.back()){
                cnt++;
            }
            else{
                if(cnt > 1){
                    ans += to_string(cnt);
                }
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        
        if(cnt > 1){
            ans += to_string(cnt);
        }
        
        s.clear();
        for(auto i:ans){
            s.push_back(i);
        }
        return s.size();
    }
};