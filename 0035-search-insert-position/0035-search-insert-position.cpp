class Solution {
public:
    int searchInsert(vector<int>& nums, int key) {
        int ans=0;
        int s=0;
        int e=nums.size()-1;
        int m = s+ (e-s)/2;
        
         while(s<=e){
            if(nums[m]==key){
                ans = m;
                break;
            }
            
            if(nums[m]<key){
                ans = m+1;
                s= m+1;
            }
            else if(nums[m]>key){
                e = m-1;
            }
             
            m = s + (e-s)/2;
        }
        return ans;
    }
};