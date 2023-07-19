class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> st;
        
        for(auto i:tokens){
            
            if(i == "/" || i=="+" || i=="-" || i=="*"){
                int nums1 = stoi(st.top());
                st.pop();
                int nums2 = stoi(st.top());
                st.pop();
                if(i == "/"){
                    st.push(to_string(nums2/nums1));
                }
                else if(i == "*"){
                    st.push(to_string(nums2*nums1));
                }
                else if(i == "+"){
                    st.push(to_string(nums2+nums1));
                }
                else if(i == "-"){
                    st.push(to_string(nums2-nums1));
                }
            }
            else{
                st.push(i);
            }
        }
        
        return stoi(st.top());
    }
};