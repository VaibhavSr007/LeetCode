class Solution {
public:
    int minOperations(int n) {
        vector<int> v;
        int x = 1;
        for(int i=0; i<n; i++){
            v.push_back(x);
            x+=2;
        }
        
        int ans = 0;
        if(n%2!=0){
            int val = v[n/2];
            for(int i=0; i<n/2; i++){
                ans += (val - v[i]);
            }
        }
        else{
            for(int i=n/2-1; i>=0; i--){
                ans += (n-v[i]);
            }
        }
        
        return ans;
        
    }
};