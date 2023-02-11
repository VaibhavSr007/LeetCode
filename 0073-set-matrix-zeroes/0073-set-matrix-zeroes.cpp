class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
//         int index_i; 
//         int index_j;
//         vector<int> v;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums[i].size(); j++){
//                 if(nums[i][j]==0){
//                     v.push_back(i);
//                     v.push_back(j);
//                 }
//             }
//         }
        
//         for(int i=0; i<v.size(); i++){
//             if(i%2==0){
//                 for(int j=0; j<nums[v[i]].size(); j++){
//                     nums[v[i]][j] = 0;
//                 }
//             }
//             else{
//                 for(int j=0; j<nums.size(); j++){
//                     nums[j][v[i]] = 0;
//                 }
//             }
//         }
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[0].size(); j++){
                if(nums[i][j]==0){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            if(i%2==0){
                for(int j=0; j<nums[0].size(); j++){
                    nums[v[i]][j] = 0;
                }
            }
            else{
                for(int j=0; j<nums.size(); j++){
                    nums[j][v[i]] = 0;
                }
            }
        }
    }
};