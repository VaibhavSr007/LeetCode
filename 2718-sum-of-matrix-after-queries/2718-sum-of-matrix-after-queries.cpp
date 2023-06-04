class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& que) {
        long long ans = 0;
        set<int> r, c;
        
        for(int i=que.size()-1; i>=0; i--){
            if(que[i][0] == 0){
                if(r.find(que[i][1]) == r.end()){
                    ans = ans + (n-c.size())*que[i][2];
                    r.insert(que[i][1]);
                }
            }
            else{
                if(c.find(que[i][1]) == c.end()){
                    ans = ans + (n-r.size())*que[i][2];
                    c.insert(que[i][1]);
                }
            }
        }
        
        return ans;
    }
};