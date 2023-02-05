class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            string x = to_string(i);
            reverse(begin(x),end(x));
            while(x!=""){
                ans.push_back(int(x.back()-'0'));
                x.pop_back();
            }
        }
        
        return ans;
    }
};