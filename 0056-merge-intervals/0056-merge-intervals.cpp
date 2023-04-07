class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) { 
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         vector<int> v;
//         v= nums[0];
        
//         for(int i=1; i<nums.size(); i++){
//             if(v[1]>=nums[i][0]){
//                 v[1] = max(v[1],nums[i][1]);
//             }
//             else{
//                 ans.push_back(v);
//                 v= nums[i];
//             }
//         }
//         ans.push_back(v);
//         return ans;
        
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        vector<int> temp = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(temp[1] >= nums[i][0]){
                temp[1] = max(temp[1],nums[i][1]);
            }
            else{
                ans.push_back(temp);
                temp = nums[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};