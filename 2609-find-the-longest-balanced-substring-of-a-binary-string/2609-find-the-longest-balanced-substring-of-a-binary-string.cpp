class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        vector<string> v;
        for(int i=0; i<s.length(); i++){
            string x = "";
            for(int j=i; j<s.length(); j++){
                x.push_back(s[j]);
                v.push_back(x);
            }
        }
        
        int ans = 0;
        for(auto sub:v){
            int cnt0 = 0, cnt1 = 0;
            bool isOned = false;
            for(auto j:sub){
                if(j=='0' && !isOned){
                    cnt0++;
                }
                else if(j=='0' && isOned){
                    break; 
                }
                else if(j=='1' && !isOned){
                    cnt1++;
                    isOned = true;
                }
                else if(j=='1' && isOned){
                    cnt1++;
                }
            }
            
            if(cnt1==cnt0){
                int cnt = 2*cnt1;
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};