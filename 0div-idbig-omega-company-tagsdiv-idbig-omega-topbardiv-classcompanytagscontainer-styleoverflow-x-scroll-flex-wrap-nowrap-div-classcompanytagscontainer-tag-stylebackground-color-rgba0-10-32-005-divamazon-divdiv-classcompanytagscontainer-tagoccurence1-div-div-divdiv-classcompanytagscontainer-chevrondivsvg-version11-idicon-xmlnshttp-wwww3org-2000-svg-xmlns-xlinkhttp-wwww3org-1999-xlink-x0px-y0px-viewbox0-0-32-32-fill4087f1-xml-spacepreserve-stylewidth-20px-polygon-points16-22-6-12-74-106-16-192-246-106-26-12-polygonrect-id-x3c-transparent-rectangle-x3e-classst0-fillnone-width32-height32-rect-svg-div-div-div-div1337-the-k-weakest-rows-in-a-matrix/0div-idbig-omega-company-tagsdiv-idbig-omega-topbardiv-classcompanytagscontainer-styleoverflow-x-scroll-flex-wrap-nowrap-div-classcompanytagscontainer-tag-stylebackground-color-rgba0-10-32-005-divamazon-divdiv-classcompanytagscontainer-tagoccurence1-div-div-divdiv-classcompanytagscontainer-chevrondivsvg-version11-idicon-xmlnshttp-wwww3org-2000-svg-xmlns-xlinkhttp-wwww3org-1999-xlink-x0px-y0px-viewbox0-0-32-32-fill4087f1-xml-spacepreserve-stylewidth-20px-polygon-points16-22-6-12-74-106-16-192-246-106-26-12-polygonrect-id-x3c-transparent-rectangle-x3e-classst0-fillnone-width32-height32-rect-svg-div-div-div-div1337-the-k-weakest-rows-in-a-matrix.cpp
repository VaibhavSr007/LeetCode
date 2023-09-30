class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> mp;
        
        for(int i=0; i<mat.size(); i++){
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    cnt++;
                }
                else{
                    break;
                }
            }
            mp[cnt].push_back(i);
        }
        
        // for(auto v:mp){
        //     cout<<v.first<<"=>";
        //     for(auto i:v.second){
        //         cout<<i<<",";
        //     }
        //     cout<<" ";
        // }
        
        
        vector<int> ans;
        bool chk = false;
        for(auto v:mp){
            for(auto i:v.second){
                ans.push_back(i);
                if(ans.size() == k){
                    chk = true;
                    break;
                }
            }
            if(chk){
                break;
            }
        }
        
        return ans;
    }
};