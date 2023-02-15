class Solution {
public:
    string add(string x, string y){
        int i=x.length()-1;
        int j=y.length()-1;
        string ans = "";
        int carry = 0;
        while(i>=0 && j>=0){
            int sum = int(x[i]-'0') + int(y[j]-'0') + carry;
            if(sum >= 10){
                carry = sum/10;
            }
            else{
                carry = 0;
            }
            ans.push_back(char((sum%10)+'0'));
            i--;
            j--;
        }
        
        while(i>=0){
            int sum = carry + int(x[i]-'0');
            if(sum >= 10){
                carry = sum/10;
            }
            else{
                carry = 0;
            }
            ans.push_back(char((sum%10)+'0'));
            i--;
        }
        while(j>=0){
            int sum = carry + int(y[j]-'0');
            if(sum >= 10){
                carry = sum/10;
            }
            else{
                carry = 0;
            }
            ans.push_back(char((sum%10)+'0'));
            j--;
        }
        if(carry != 0){
            ans.push_back(char(carry+'0'));
        }
        return ans;
    }
    
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        string s = "";
        vector<int> v;
        for(auto i:num){
            s.push_back(char('0'+i));
        }
        string x = to_string(k);
        
        string ans = add(x,s);
        
        for(int i=ans.length()-1; i>=0; i--){
            v.push_back(int(ans[i]-'0'));
        }
        
        return v;
    }
};