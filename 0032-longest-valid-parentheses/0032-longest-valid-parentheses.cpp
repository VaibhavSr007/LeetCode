class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){ // this is to pop the corresponding open bracket (since only open 
                     st.pop();               //bracket are taken in the stack)   
                }
                
                if(!st.empty()){ // if now also the stack is not empty means this may be a part of 
                    ans = max(ans,i-st.top()); // a longer valid string string so store its size (in                                                        case its the last longest valid string)
                }
                else{  // if stack is empty we need to store a prefix for a valid string same like we
                    st.push(i);  // had -1 in the start so it can tell the length of valid string
                }
            }
        }
        return ans;
    }
};