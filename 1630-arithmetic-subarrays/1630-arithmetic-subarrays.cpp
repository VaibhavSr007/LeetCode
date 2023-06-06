class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> v;
            for(int j=l[i]; j<=r[i]; j++){
                v.push_back(nums[j]);
            }
            sort(v.begin(), v.end());
            
            if(v.size() == 1){
                ans.push_back(true);
            }
            else{
                set<int> s;
                for(int x=0; x<v.size()-1; x++){
                    s.insert(v[x] - v[x+1]);
                }
                if(s.size() == 1){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};