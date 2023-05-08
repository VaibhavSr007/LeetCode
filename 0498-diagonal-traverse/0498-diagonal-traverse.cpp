class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,vector<int>> mp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                mp[i+j].push_back(mat[i][j]);
                
            }
        }
        
        vector<pair<int,vector<int>>> v;
        
        for(auto i:mp){
            v.push_back(i);
        }
        
        vector<int> ans;
        
        for(auto i:v){
            if(i.first%2 == 0){
                reverse(begin(i.second),end(i.second));
            }
            for(auto j:i.second){
                ans.push_back(j);
            }
        }
        
        return ans;
    }
};