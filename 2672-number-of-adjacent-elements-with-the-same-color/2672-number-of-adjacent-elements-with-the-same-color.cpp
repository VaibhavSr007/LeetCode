class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> v(n,0);
        int ans = 0;
        vector<int> res;
        for(auto i:queries){
            if(i[0]>0 && v[i[0]]!=0 && v[i[0]] == v[i[0]-1]){
                ans--;
            }
            if(i[0]<n-1 && v[i[0]]!=0 && v[i[0]] == v[i[0]+1]){
                ans--;
            }
            
            v[i[0]]= i[1];
            
            if(i[0]>0  && v[i[0]] == v[i[0]-1]){
                ans++;
            }
            if(i[0]<n-1 && v[i[0]] == v[i[0]+1]){
                ans++;
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};