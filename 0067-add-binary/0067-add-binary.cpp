class Solution {
public:
    
    string addBinary(string a, string b) {
        
        char carry = '0';
        string ans = "";
        int i = a.length()-1;
        int j = b.length()-1;
        
        while(i>=0 && j>=0){
            if(carry == '0'){
                if(a[i] =='0' && b[j]=='0'){
                    ans.push_back('0');
                    carry = '0';
                }
                else if((a[i] =='0' && b[j]=='1') || (a[i] =='1' && b[j]=='0')){
                    ans.push_back('1');
                    carry = '0';
                }
                else if(a[i] =='1' && b[j]=='1'){
                    ans.push_back('0');
                    carry = '1';
                }
            }
            else{
                if(a[i] =='0' && b[j]=='0'){
                    ans.push_back('1');
                    carry = '0';
                }
                else if((a[i] =='0' && b[j]=='1') || (a[i] =='1' && b[j]=='0')){
                    ans.push_back('0');
                    carry = '1';
                }
                else if(a[i] =='1' && b[j]=='1'){
                    ans.push_back('1');
                    carry = '1';
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(carry=='0'){
                if(a[i]=='0'){
                    ans.push_back('0');
                    carry = '0';
                }
                else{
                    ans.push_back('1');
                    carry = '0';
                }
            }
            else{
                if(a[i]=='0'){
                    ans.push_back('1');
                    carry = '0';
                }
                else{
                    ans.push_back('0');
                    carry = '1';
                }
            }
            i--;
        }
        while(j>=0){
            if(carry=='0'){
                if(b[j]=='0'){
                    ans.push_back('0');
                    carry = '0';
                }
                else{
                    ans.push_back('1');
                    carry = '0';
                }
            }
            else{
                if(b[j]=='0'){
                    ans.push_back('1');
                    carry = '0';
                }
                else{
                    ans.push_back('0');
                    carry = '1';
                }
            }
            j--;
        }
        if(carry!='0')
            ans.push_back(carry);
        reverse(begin(ans),end(ans));
        return ans;
    }
};