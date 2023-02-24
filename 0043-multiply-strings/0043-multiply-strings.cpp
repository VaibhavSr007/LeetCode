class Solution {
public:
    
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int n = num1.length(), m=num2.length();
        vector<int> ans(n+m,0);
        for(int i=num1.length()-1; i>=0; i--){
            for(int j=num2.length()-1; j>=0; j--){
                int dig = (num1[i]-'0')*(num2[j]-'0') + ans[i+j+1];
                ans[i+j+1] = dig%10;
                ans[i+j] += dig/10;
            }
        }
        
        string res = "";
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i]<<":";
            res.push_back(ans[i]+'0');
        }
        cout<<" ";
        
        while(res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};