class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<vector<int>> q;
        vector<vector<int>> vis (n, vector<int> (m,0));
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && vis[i][j] == 0){
                    vector<int> v;
                    q.push({i,j});
                    vis[i][j] = 1;
                    v.push_back(i);
                    v.push_back(j);
                    
                    while(!q.empty()){
                        vector<int> temp = q.front();
                        q.pop();
                        
                        for(auto d:dir){
                            int x =  d[0] + temp[0];
                            int y =  d[1] + temp[1];
                            
                            if(x<n && y<m && x>=0 && y>=0 && land[x][y]==1 && vis[x][y]==0){
                                q.push({x,y});
                                vis[x][y] = 1;
                            }
                        }
                        if(q.size() == 0){
                            v.push_back(temp[0]);
                            v.push_back(temp[1]);
                        }
                    }
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};