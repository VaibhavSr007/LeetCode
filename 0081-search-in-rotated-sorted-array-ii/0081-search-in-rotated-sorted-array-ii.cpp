class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        if(s.find(target) != s.end()){
            return true;
        }
        return false;
    }
};