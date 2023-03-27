class Solution {
public:
    int reverse(int n) {
    int rev=0;
   	for(int i=1; n!=0; i++){
		
		int rem = n%10;
	    n = n/10;
		if(rev < INT_MIN/10 || rev > INT_MAX/10){
			return 0;
		}
		rev = rev*10 + rem;
	  } 
	return rev; 
    }
};