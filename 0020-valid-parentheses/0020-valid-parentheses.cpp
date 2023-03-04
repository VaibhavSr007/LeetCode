class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1){
            return false;
        }
        
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.size()!=0){
                    if(s[i]==')' && st.top()=='('){
                        st.pop();
                    }
                    else if(s[i]=='}' && st.top()=='{'){
                        st.pop();
                    }
                    else if(s[i]==']' && st.top()=='['){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        if(st.size()==0){
            return true;
        }
        
        return false;
    }
};