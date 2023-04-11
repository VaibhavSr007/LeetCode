class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        
        int count = 0;
        map<int,pair<int,int>> mp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    // mp[nums[i] + nums[j] + nums[k]] = {mp[nums[i] + nums[j] + nums[k]].first+1, k};
                    for(int l=k+1; l<nums.size(); l++){
                        if(nums[i] + nums[j] + nums[k] == nums[l]){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};