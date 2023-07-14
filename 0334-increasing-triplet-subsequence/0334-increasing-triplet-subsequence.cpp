class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s1 = INT_MAX, s2 = INT_MAX;
        
        for(auto i:nums){
            if(i < s1){
                s1 = i;
            }
            else if(i > s1 && i < s2){
                s2 = i;
            }
            else if(i > s1 && i> s2){
                return true;
            }
        }
        
        return false;
    }
};