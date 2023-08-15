class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1, s2;
        vector<int> v1, v2;
        
        for(auto i:nums1){
            s1.insert(i);
        }
        
        for(auto i:nums2){
            s2.insert(i);
        }
        
        for(auto i:s1){
            if(s2.find(i) == s2.end()){
                v1.push_back(i);
            }
        }
        
        for(auto i:s2){
            if(s1.find(i) == s1.end()){
                v2.push_back(i);
            }
        }
        
        return {v1,v2};
    }
};