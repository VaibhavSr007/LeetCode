class Solution {
public:
    
    bool solve(int i, int k, int sum, vector<int>& nums, vector<int> &res){
        
        if(i==-1){
            return true;
        }
        
        for(int idx = 0; idx<k; idx++){
            if(res[idx] + nums[i] <= sum){
                res[idx] += nums[i];
                if(solve(i-1, k, sum, nums, res)){
                    return true;
                }
                res[idx] -= nums[i];
            }
            
            if(res[idx] == 0){
                break;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        for(int i:nums){
            sum += i;
        }
        sum /= k;
        vector<int> res(k,0);
        sort(nums.begin(), nums.end());
        return solve(nums.size()-1, k, sum, nums, res);
    }
};