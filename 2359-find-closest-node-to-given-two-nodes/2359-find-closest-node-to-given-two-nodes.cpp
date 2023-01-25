class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> v1(n,-1);
        vector<int> vis(n,0);
        int cnt =0;
        while(node1 != -1 && vis[node1]==0){
            vis[node1]=1;
            v1[node1] = cnt++;
            node1 = edges[node1];
        }
        
        cnt= 0;
        vector<int> v2(n,-1);
        vector<int> vis1(n,0);
        while(node2 != -1 && vis1[node2]==0){
            vis1[node2]=1;
            v2[node2] = cnt++;
            node2 = edges[node2];
        }
        
        int ans = -1;
        int mini = INT_MAX;
        for(int i=0; i<edges.size(); i++){
            if(v1[i]==-1 || v2[i]==-1){
                continue;
            }
            
            int res = max(v1[i],v2[i]);
            if(res < mini){
                mini = res;
                ans = i;
            }
            else if(res==mini){
                ans = min(i,ans);
            }
        }
        
        return ans;
    }
};