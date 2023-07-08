class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans= 0;
        vector<long long> v;
        for(int i=0; i<weights.size()-1; i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        
        sort(v.begin(), v.end());
        
        int j = v.size()-1;
        for(int i=0; i<k-1; i++){
            ans -= v[i];
            ans += v[j--];
        }
        
        return ans;
    }
};