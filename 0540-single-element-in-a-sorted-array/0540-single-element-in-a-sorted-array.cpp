class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++){
        //     ans = ans^nums[i];        good but not optimized
        // }
        // return ans;
        
        // int ans;
        // if(nums.size()==1){
        //     return 1;
        // }
        // for(int i=0; i<nums.size(); i++){
        //     if(i<nums.size()-1 && i%2==0){
        //         if(nums[i]!=nums[i+1]){
        //             ans = nums[i];
        //             break;
        //         }                             // TC O(n)  SC o(1)
        //     }
        //     else if(i==nums.size()-1){
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;
        
        
        int s = 0;
        int e = nums.size()-2;
        int m = s + (e-s)/2;
        
        while(s<=e){
            // if(m%2==0){
            //     if(nums[m] == nums[m+1]){
            //         s = m+1;   // this means we are in left part of single element
            //     }
            //     else{
            //         e = m-1;   // this means we are in right part of single element
            //     }
            // }
            // else{
            //     if(nums[m] == nums[m-1]){
            //         s = m+1;
            //     }
            //     else{
            //         e = m-1;
            //     }
            // }
            if(nums[m] == nums[m^1]){ // here m^1 gives next m+1 if m is even n m-1 if m = odd
                                      // so we can escape even/odd finding step
                s = m+1;        // this means we are left part of single ele so move right
            }
            else{
                e = m-1;       // this means we are in right part so left
            }
            m = s + (e-s)/2;
        }
        return nums[s];
    }
};