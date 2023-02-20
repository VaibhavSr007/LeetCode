class Solution {
public:
    int maxProfit(vector<int>& nums) {
//         int mini = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i; j<nums.size(); j++){     //brute force approach
//                 int a = nums[i] - nums[j];
//                 mini = min(a,mini);
//             }
//         }
        
//         return abs(mini);
        
        int mini = INT_MAX;
        int max_pro = 0;
        
        for(int i=0; i<nums.size(); i++){
            mini = min(mini,nums[i]);
            
            max_pro = max(max_pro,nums[i]-mini);
        }
        return max_pro;
    }
};