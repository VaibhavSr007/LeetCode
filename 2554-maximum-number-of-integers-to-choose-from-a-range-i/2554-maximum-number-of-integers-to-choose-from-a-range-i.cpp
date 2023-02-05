class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        int sum = 0, cnt = 0;
        for(auto i:banned){
            s.insert(i);
        }
        for(int i=1; i<=n; i++){
            if(s.find(i) == s.end()){
                if(sum+i <= maxSum){
                    cnt++;
                    sum += i;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};