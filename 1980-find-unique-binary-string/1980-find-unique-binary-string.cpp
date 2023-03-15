class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        set<string> s;
        for(auto i:nums){
            s.insert(i);
        }
        while(true){
            for(int i=0; i<nums.size(); i++){
                ans.push_back(char(rand()%2 + '0'));
            }
            if(s.find(ans)==s.end()){
                return ans;
            }
            ans = "";
        }
        return ans;
    }
};