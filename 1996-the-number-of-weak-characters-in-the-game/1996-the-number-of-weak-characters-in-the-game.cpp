class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] < b[0] || (a[0] == b[0] && a[1] > b[1])){
            return true;
        }
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
//         int ans=0;
//         sort(pro.begin(), pro.end());
        
//         vector<vector<vector<int>>> v;
//         vector<vector<int>> res;
//         res.push_back(pro[0]);
//         for(int i=1; i<pro.size(); i++){
//             if(res.size()==0){
//                 res.push_back(pro[i]);
//             }
//             else{
//                 if(res.back()[0] == pro[i][0]){
//                     res.push_back(pro[i]);
//                 }
//                 else{
//                     v.push_back(res);
//                     res.clear();
//                     res.push_back(pro[i]);
//                 }
//             }
//         }
//         v.push_back(res);
        
//         stack<vector<int>> st;
//         for(int i=0; i<v.size(); i++){
//             if(st.empty()){
//                 for(int j=v[i].size()-1; j>=0; j--){
//                     st.push(v[i][j]);
//                 }
//             }
//             else{
//                 for(int j=0; j<v[i].size(); j++){
//                     while(!st.empty() && st.top()[1] < v[i][j][1]){
//                         ans++;
//                         st.pop();
//                     }
//                 }
//                 for(int j=v[i].size()-1; j>=0; j--){
//                     st.push(v[i][j]);
//                 }
//             }
//         }
        
//         return ans;
        
        int ans=0;
        sort(pro.begin(), pro.end(),cmp);
        stack<vector<int>> st;
        for(int i=0; i<pro.size(); i++){
            if(st.empty()){
                st.push(pro[i]);
            }
            else{
                while(!st.empty() && st.top()[0] < pro[i][0] && st.top()[1] < pro[i][1]){
                    ans++;
                    st.pop();
                }
                st.push(pro[i]);
            }
        }
        return ans;
    }
};