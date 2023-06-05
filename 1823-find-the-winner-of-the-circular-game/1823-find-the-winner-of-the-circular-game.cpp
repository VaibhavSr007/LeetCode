class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=0; i<n; i++){
            v.push_back(i);
        }
        int idx = 0;
        while(v.size() != 1){
            idx = (idx + (k-1))%v.size();
            v.erase(v.begin()+idx);
            idx = (idx)%v.size();
        }
        return v[0]+1;
    }
};