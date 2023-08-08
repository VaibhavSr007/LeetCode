class Solution {
public:
    static int bin_search(vector<int> nums, int target,int s, int e){
        int ans= -1;
        
        int m = s + (e-s)/2;
        while(s<=e){
            if(nums[m]==target){
                ans = m;
                break;
            }
            else if(nums[m]>target){  // for finding the target in the correct part of array
                e = m-1;
            }
            else{
                s = m+1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
    
    
    int search(vector<int>& nums, int target) {
        int e = nums.size()-1;
        int s = 0;
        int m = s + (e-s)/2;
        while(s<e){
            if(nums[m]>=nums[0]){
                s = m+1;
            }
            else{
                e = m;
            }              // finding the pivot to divide array in two searching parties
            
            m = s + (e-s)/2;
        }
        
        // cout << s;
        
        if(nums.size()==1){
            if(nums[0]==target){  // edge case if size is 1 thn see check target and return
                return 0;         // else it will give problem in (nums[m-1]) part ie idx 0-1
            }
            return -1;
        }
        
        if(target>=nums[0] && target<=nums[m-1]){ //    assigning the sub-array to search based
            return bin_search(nums, target, 0,m-1); //  on the target
        }
        else{
            return bin_search(nums, target, m,nums.size()-1);
        }
    }
};