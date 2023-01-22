class Solution {
public:
    int alternateDigitSum(int n) {
        int sum =  0;
        string s = to_string(n);
        
        for(int i=0; i<s.length(); i++){
            if(i%2==0){
                sum += int(s[i]-'0');
            }
            else{
                sum -= int(s[i]-'0');
            }
        }
        
        return sum;
    }
};