class Solution {
public:
    vector<vector<int>> generate(int nums) {
//         vector<vector<int>> ans;
//         int x;
        
//         for(int i=0; i<nums; i++){
//             vector <int> v;
//             for(int j=0; j<=i; j++){
//                 if(j==0 || j==i){
//                     v.push_back(1);
//                 }
//                 else{
//                     x = ans[i-1][j-1] + ans[i-1][j];
//                     v.push_back(x);
//                 }
//             }
//             ans.push_back(v);;
//         }
//         return ans;
        
        vector<vector<int>> ans;
        
        for(int i=0; i<nums; i++){
            vector<int> v;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    v.push_back(1);
                }
                else{
                    int val = ans[i-1][j] + ans[i-1][j-1];
                    v.push_back(val);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};