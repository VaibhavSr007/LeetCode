class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a;
        int y = b;
        int z = c;
        int cnt=0;
        while(z || y || x){
            int t1 = x&1;
            int t2 = y&1;
            int t3 = z&1;
            x /= 2;
            y /= 2;
            z /= 2;
            
            if(t3==1 && t1==0 && t2==0){
                cnt++;
            }
            if(t3==0 && t1==1 && t2==0){
                cnt++;
            }
            else if(t3==0 && t1==0 && t2==1){
                cnt++;
            }
            else if(t3==0 && t1==1 && t2==1){
                cnt+=2;
            }
        }
        return cnt;
    }
};