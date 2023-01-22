class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        for(auto i:nums1){
            s.insert(i);
        }
        
        for(auto i:nums2){
            if(s.find(i) != s.end()){
                return i;
            }
        }
        
        return -1;
    }
};