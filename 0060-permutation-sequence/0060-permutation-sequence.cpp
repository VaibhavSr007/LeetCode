class Solution {
public:
//     void solve(int idx, string s, vector<string> &ans){
//         if(idx >= s.length()){
//             ans.push_back(s);
//             return ;
//         }
        
//         for(int i=idx; i<s.length(); i++){
//             swap(s[idx],s[i]);
//             solve(idx+1,s,ans);
//             swap(s[idx],s[i]);
//         }
//     }
    string getPermutation(int n, int k) {
        vector<int> s;
        string ans;
        for(int i=1; i<=n; i++){
            s.push_back(i);
        }
        
        int cnt  =1;
        while(cnt != k){
            cnt++;
            next_permutation(s.begin(),s.end());
        }
        
        for(auto i:s){
            ans.push_back(char(i)+'0');
        }
        return ans;
    }
};