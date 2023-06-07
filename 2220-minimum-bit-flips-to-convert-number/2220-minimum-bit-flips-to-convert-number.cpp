class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(start || goal){
            int t1 = start&1;
            int t2 = goal&1;
            start /= 2;
            goal /= 2;
            
            if(t1 == t2){
                continue;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};