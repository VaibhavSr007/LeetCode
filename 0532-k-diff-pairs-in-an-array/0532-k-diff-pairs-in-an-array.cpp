class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){ return 0;}
        set<vector<int>> s;
        int i=0, j=1, cnt =0;
        while(j<nums.size()){
            if(i==j){
                j++;
                continue;
            }
            
            if(nums[j] - nums[i] == k){
                vector<int> v = {nums[i], nums[j]};
                if(s.find(v) == s.end()){
                    cnt++;
                    s.insert(v);
                }
                j++;
            }
            else if(nums[j] - nums[i] < k){
                j++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};