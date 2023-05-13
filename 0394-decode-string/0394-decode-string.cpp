class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> st1;
        int num = 0;
        string res = "";
        
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(i > 0 && s[i-1] >= '0' && s[i-1] <= '9'){
                    num = 10*num + (int(s[i]) - '0');
                }
                else{
                    num = (int(s[i]) - '0');
                }
            }
            else if(s[i] == '['){
                st1.push(res);
                res = "";
                st.push(num);
            }
            else if(s[i] == ']'){
                string str = st1.top();
                st1.pop();
                num = st.top();
                st.pop();
                for(int j=0; j<num; j++){
                    str += res;
                }
                res = str;
                
            }
        }
        return res;
    }
};