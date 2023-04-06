class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
//         int x = -1;
//         int y;        

//         //storing the index of first value that is smaller thn its next value
//         for(int i=nums.size()-1; i>0; i--){
//             if(nums[i-1]<nums[i]){
//                 x = i-1;
//                 break;
//             }
//         }
// // checking if the array is already sorted in reversed manner if yes thn sort n send
//         if(x<0){
//             reverse(nums.begin(),nums.end());
//         }
// // finding the first num which is graeter thn the first value i.e smaller than its next num which is num[x] and swapping it with num[x] and reversing the part after idx x+1;
//         else{
//             for(int i=nums.size()-1; i>x; i--){
//                 if(nums[i]>nums[x]){
//                     y = i;
//                     break;
//                 }
//             }
//             swap(nums[y],nums[x]);
//             reverse(nums.begin()+(x+1),nums.end());
//         }  
        
        next_permutation(nums.begin(),nums.end());
    }
};