class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        long long m = abs(n);
        
        
        while(m > 0){
            if(m%2==0){
                x = x*x;
                m = m / 2;
            }
            else{
                ans = ans*x;
                m = m - 1;
            }
        }
        
        if(n < 0){
            return 1/ans;
        }
        
        return ans;
    }
};