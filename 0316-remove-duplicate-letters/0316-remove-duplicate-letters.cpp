class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char,int> mp;
        
        vector<int> vis(26,0);
        string ans = "";
        for(auto i:s){
            if(mp.find(i)==mp.end()){
                mp[i] = 1;
            }
            else{
                mp[i]++;
            }
        }
        
       
        for(int i=0; i<s.length(); i++){
            mp[s[i]]--;
            if(vis[s[i]-'a']==1 || (!st.empty() && st.top()==s[i])){
                continue;
            }
            while(!st.empty() && s[i]<st.top() && mp[st.top()] > 0){
                vis[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};