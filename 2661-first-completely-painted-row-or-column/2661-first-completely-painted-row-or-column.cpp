class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        map<int,int> row;
        map<int,int> col;
        int ans  = INT_MAX;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]].push_back(i);
                mp[mat[i][j]].push_back(j);
            }
        }
        
        for(int k=0; k<arr.size(); k++){
            int x = mp[arr[k]][0];
            int y = mp[arr[k]][1];
            
            row[x]++;
            if(row[x] == m){
                return k;
            }
            
            col[y]++;
            if(col[y] == n){
                return k;
            }
            
            vis[x][y] = 1;
            
        }
        return ans;
    }
};