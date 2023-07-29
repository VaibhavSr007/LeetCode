class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;
        for(auto i:strs){
            int x =i.length();
            len = min(x, len);
        }
        
        string ans = "";
        for(int i=0; i<len; i++){
            char tar = strs[0][i];
            for(auto w:strs){
                if(tar != w[i]){
                    return ans;
                } 
            }
            ans.push_back(tar);
        }
        
        return ans;
    }
};