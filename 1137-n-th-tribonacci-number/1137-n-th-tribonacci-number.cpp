class Solution {
public:
    int dp[100]={0};
    
    int fib (int n){
        if(n==0){
            return 0;
        }else if(n==1){
            dp[n] = 1;
            return 1;
        }
        else if(n==2){
            dp[n] = 1;
            return 1;
        }
        
        if(dp[n] != 0){
            return  dp[n];
        }
        
        dp[n] = fib(n-1)+fib(n-2)+fib(n-3);
        return dp[n];
    }
    
    int tribonacci(int n) {
        return fib(n);
    }
};