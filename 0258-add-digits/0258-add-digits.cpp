class Solution {
public:
    
    int addDigits(int num){
         
        // int sum = num;  
        // int x;   
        //  while(sum>=10){   
        //     x = sum;
        //     sum = 0;
        //     while(x!=0){
        //         int rem = x%10;
        //         sum = sum + rem;
        //         x = x/10;
        //     }
        //  }
        //  return sum;
        
        while(num>=10){
            int copy = num;
            int sum = 0;
            while(copy!=0){
                sum += copy%10;
                copy /=10;
            }
            num = sum;
        }
        return num;
    }
    
};

 