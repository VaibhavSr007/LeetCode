class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<int> st;
        string ans = "";
        for(auto i:s){
            if(st.size() == 0){
                st.push(i);
            }
            else{
                
                if(st.top() == '(' && i==')'){
                    st.pop();
                    if(st.empty()){
                        continue;
                    }
                }
                else{
                    st.push(i);
                }
                ans += i;
            }
        }
        return ans;
    }
};