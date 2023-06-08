class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& nums) {
        
        map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i][0]].push_back(nums[i][1]);
            mp[nums[i][1]].push_back(nums[i][0]);
        }
        
        vector<int> vis(n,0);
        queue<int> q;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                q.push(i);
                vis[i] = 1;
                vector<int> v;
                
                while(!q.empty()){
                    int temp = q.front();
                    v.push_back(temp);
                    q.pop();
                    
                    for(auto j:mp[temp]){
                        if(vis[j] == 0){
                            q.push(j);
                            vis[j] = 1;
                        }
                    }
                }
                int size = v.size();
                bool chk = true;
                for(auto j:v){
                    if(mp[j].size() != size-1){
                        chk = false;
                        break;
                    }
                }
                if(chk){
                    ans++;
                }
            }
        }
        return ans;
    }
};