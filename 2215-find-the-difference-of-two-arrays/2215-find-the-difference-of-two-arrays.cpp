class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a, b;
        vector<int> x,y;
        
        for(auto i:nums1){
            a.insert(i);
        }
        for(auto i:nums2){
            b.insert(i);
        }
        
        for(auto i:nums1){
            if(b.find(i) == b.end()){
                x.push_back(i);
            }
        }
        for(auto i:nums2){
            if(a.find(i) == a.end()){
                y.push_back(i);
            }
        }
        
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        sort(y.begin(),y.end());
        y.erase(unique(y.begin(),y.end()),y.end());
        
        return {x,y};
    }
};