class Solution {
public:
    vector<int> nextGr(vector<int>& v){
        stack<int> st;
        st.push(-1);
        vector<int> ans;
        for(int i=v.size()-1; i>=0; i--){
            while(st.top()!=-1 && v[i] > v[st.top()]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
    
    int trap(vector<int>& he) {
        int n = he.size();
        // left greatest element array;
        int maxi = INT_MIN;
        vector<int> l;
        for(int i=0; i<n; i++){
            maxi = max(maxi,he[i]);
            l.push_back(maxi);
        }
        // right greatest element array;
        maxi = INT_MIN;
        vector<int> r;
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi,he[i]);
            r.push_back(maxi);
        }
        reverse(begin(r),end(r));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout<<l[i]<<":"<<r[i]<<" ";
            int min_he = min(l[i],r[i]);
            ans += (min_he - he[i]);
        }
        // cout<<endl;
        return ans;
    }
};