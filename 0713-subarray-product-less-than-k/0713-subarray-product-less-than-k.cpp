class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int pro = 1;
        // int cnt = 0;
        // for(int i = 0; i<nums.size(); i++){
        //     pro = 1;
        //     for(int j=i; j<nums.size(); j++){
        //         pro *= nums[j];
        //         if(pro<k){                        // brute force
        //             cnt++;
        //         }
        //          else{
        //             break;
        //         }   
        //     }
        // }
        // return cnt;
        
        
        if(k<=1){
            return 0;
        }
        
        long long pro = 1;
        int cnt = 0;
        int i=0, j=0;
        while(j < nums.size()){
            pro *= nums[j];
            
            while(pro >= k){
                pro /= nums[i];
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        
        return cnt;
    }
};