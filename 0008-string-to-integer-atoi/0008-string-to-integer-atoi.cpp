class Solution {
public:
    
    void solve(int idx, string s , int &rem, int sign){
        if(idx >= s.length() || (s[idx] < '0' || s[idx] > '9')){
            return ;
        }
        
        int dig = (int(s[idx]) - '0')*sign;
        if(sign == 1 && (rem > INT_MAX/10 || (rem == INT_MAX/10 && dig > INT_MAX%10)) ) {rem = INT_MAX; return;}
        if(sign == -1 && (rem < INT_MIN/10 || (rem == INT_MIN/10 && dig < INT_MIN%10)) ) {rem = INT_MIN; return;}
        rem = rem*10 + dig;
        solve(idx+1, s, rem, sign);
        
    }
    int myAtoi(string s) {
        
        //**************************** approach 1***************************************
        
//         int i=0; 
//         int rem = 0;
//         int sign = 1;
        
//         while(s[i] == ' '){
//             i++;
//         }
        
//         if(s[i] == '-' || s[i] == '+' ){
//             if(s[i] == '-' ){
//                 sign = -1;
//             }
//             i++;
//         }
        
//         while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            
//             int dig = (s[i]-'0')*sign;
//             if(sign == 1 && (rem > INT_MAX/10 || (rem == INT_MAX/10 && dig > INT_MAX%10)) ) {return INT_MAX;}
//             if(sign == -1 && (rem < INT_MIN/10 || (rem == INT_MIN/10 && dig < INT_MIN%10)) ) {return INT_MIN;}
//             rem = rem*10 + dig;
//             i++;
//         }
        
//         return rem;
        
        int rem = 0;
        int sign = 1;
        int idx = 0;
        while(s[idx] == ' '){
            idx++;
        }
        if(s[idx] == '-' || s[idx] == '+'){
            if(s[idx] == '-'){
                sign = -1;
            }
            idx++;
        }
        
        solve(idx, s, rem, sign);
        return rem;
    }
};