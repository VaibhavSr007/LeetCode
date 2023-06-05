class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int i=asteroids.size()-1;
        while(i>=0){
            if(st.empty()){
                st.push(asteroids[i]);
                i--;
            }
            else if(asteroids[i] > 0 && st.top() < 0){
                if(abs(st.top()) > asteroids[i]){
                    i--;
                }
                else if(abs(st.top()) == asteroids[i]){
                    st.pop();
                    i--;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(asteroids[i]);
                i--;
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};