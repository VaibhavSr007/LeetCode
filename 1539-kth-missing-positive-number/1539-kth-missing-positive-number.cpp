class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s;
        for(auto i:arr){
            s.insert(i);
        }
        int cnt = 0;
        int i=1;
        while(true){
            if(s.find(i)==s.end()){
                cnt++;
            }
            if(cnt==k){
                return i;
            }
            i++;
        }
        return -1;
    }
};