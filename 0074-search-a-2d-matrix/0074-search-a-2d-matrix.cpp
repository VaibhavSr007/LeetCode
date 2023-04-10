class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        
//         for(int i=0; i<nums.size(); i++){
//             int s = 0;
//             int e = nums[i].size()-1;
//             int m = s + (e-s)/2;
//             while(s<=e){
//                 if(nums[i][m]==target){
//                     return true;
//                     break;                //  approach 1
//                 }
//                 else if(nums[i][m]>target){
//                     e = m-1;
//                 }
//                 else if(nums[i][m]<target){
//                     s = m+1;
//                 }
//                 m = s + (e-s)/2;
//             }
//         }
        
//         int s = 0;
//         int e = nums.size()*nums[0].size()-1;
//         int m = s + (e-s)/2;
        
//         while(s<=e){
//             int col = m/nums[0].size();  // formula to find colm of mid element
//             int row = m%nums[0].size();  // formula to find row of mid element
            
//             if(nums[col][row]==target){
//                 return true;
//             }
//             else if(nums[col][row]>target){    // appraoch 2
//                 e = m-1;
//             }
//             else if(nums[col][row]<target){
//                 s = m+1;
//             }
//             m = s + (e-s)/2;
//         }
        
        
//         return false;
        
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                s.insert(nums[i][j]);
            }
        }
        
        return s.find(target) != s.end();
    }
};