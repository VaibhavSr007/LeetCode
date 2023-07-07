class Solution {
public:
    bool solve(int idx, int n, set<string> s, string &ans, string str){
        if(idx == n){
            if(s.find(str) == s.end()){
                ans = str;
                return true;
            }
            return false;
        }
        
        str.push_back('1');
        if(solve(idx+1, n, s, ans, str)){
            return true;
        }
        str.pop_back();
        
        str.push_back('0');
        if(solve(idx+1, n, s, ans, str)){
            return true;
        }
        str.pop_back();
        
        
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "", str= "";
        set<string> s;
        
        for(auto i:nums){
            s.insert(i);
        }
        
        int x = nums[0].length();
        solve(0, x, s, ans, str);
        
        return ans;
    }
};