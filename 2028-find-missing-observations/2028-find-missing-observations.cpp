class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int tot = n+rolls.size();
        int sum = 0;
        for(auto i:rolls){
            sum += i;
        }
        float val = (tot*mean) - sum;
        
        float x = val/float(n);
        
        cout<<x<<" ";
        if(x < 1 || x > 6){
            return {};
        }
        
        int rem = (n-1)*int(x);
        val -= rem;
        for(int i=0; i<(n-1); i++){
            if(val-6 > 0 && int(x) < 6){
                int res = 6 - int(x);
                val -= res;
                ans.push_back(int(x)+res);
            }
            else{
                ans.push_back(int(x));
            }
            
        }
        ans.push_back(val);
        return ans;
    }
};