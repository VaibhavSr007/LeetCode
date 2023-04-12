class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) { 
        int n = s.length() + spaces.size();
        string ans = "";
        int idx = 0;
        
        for(int i=0; i<spaces.size(); i++){
            spaces[i] += i;
        }
        
        set<int> st;
        for(auto i:spaces){
            st.insert(i);
        }
        
        for(int i=0; i<n; i++){
            if(st.find(i) != st.end()){
                ans += ' ';
            }
            else{
                ans += s[idx++];
            }
        }
        
        return ans;
    }
};