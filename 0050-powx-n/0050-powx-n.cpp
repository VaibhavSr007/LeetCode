class Solution {
public:
    
    long double power(double x, int n){
        long double ans;
        if(n==0){
            return 1;
        }
        
        // if(n%2==0){
        //     ans = power(x,n/2)*power(x,n/2);
        // }
        // else{
        //     ans = x*power(x,n/2)*power(x,n/2);
        // }
        
                // OR
        
        ans = x*power(x,n-1);
        
        
        return ans;
    }
    
    long double myPow(double x, int n) {
//         long double ans = power(x,abs(n));
        
        
//         if(n<0){
//             ans = 1/ans;
//         }
        
//         return ans;
       
        long double ans = 1;
        long long m = abs(n);
        
        while(m>0){
            if(m%2==0){
                x = x*x;
                m = m/2;
            }
            else{
                ans = ans*x;
                m = m-1;
            }
        }
        
        if(n<0){
            ans = 1/ans;
        }
        return ans;
    }
};