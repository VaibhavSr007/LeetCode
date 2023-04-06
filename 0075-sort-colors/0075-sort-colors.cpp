class Solution {
public:
    // int partition(vector<int>& nums, int s,int e){
    //     int cnt = 0;
    //     for(int i=s+1; i<=e; i++){
    //         if(nums[i]<nums[s]){
    //             cnt++;
    //         }
    //     }
    //     int pvt_idx = s +cnt;
    //     swap(nums[s],nums[pvt_idx]);
    //     int i=s;
    //     int j=e;
    //     while(i<pvt_idx && j>pvt_idx){          quick sort soln
    //         while(nums[i]<nums[pvt_idx]){
    //             i++;
    //         }
    //         while(nums[j]>nums[pvt_idx]){
    //             i--;
    //         }
    //         if(i<pvt_idx && j>pvt_idx){
    //             swap(nums[i],nums[j]);
    //         }
    //     }
    //     return pvt_idx;
    // }
    
//     void quick_sort(vector<int>& nums , int s, int e){
//         if(s>=e){
//             return ;
//         }
        
//         int p = partition(nums,s,e);
        
//         quick_sort(nums,s,p-1);
//         quick_sort(nums,p+1,e);
//     }
    
//     void sor(vector<int>& nums, int n){
//         if(n==1 || n==0){
//             return ;
//         }  
        
//         for(int i=0; i<n-1; i++){                 recursive sort solm
//             if(nums[i]>nums[i+1]){
//                 swap(nums[i],nums[i+1]);
//             }
//         }
        
//         sor(nums,n-1);
//     }
    
    void sortColors(vector<int>& nums) {
          // quick_sort(nums,0,nums.size()-1);
        
        // sor(nums,nums.size());   // recursive approach
            
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]>nums[j]){             // brute force selectn sort
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        
        // sort(nums.begin(),nums.end());   stl soln
        
//         int s =0;
//         int m=0;
//         int e = nums.size()-1;
        
//         while(m<=e){
//             if(nums[m]==0){             // dutch national flag approach  best
//                 swap(nums[m],nums[s]);
//                 s++;
//                 m++;
//             }
//             else if(nums[m]==1){
//                 m++;
//             }
//             else if(nums[m]==2){
//                 swap(nums[e],nums[m]);
//                 e--;
//             }
//         }
        
//         int zero = 0;
//         int one  = 0;
//         int two  = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]==0){
//                 zero++;
//             }
//             else if(nums[i]==1){
//                 one++;
//             }
//             else if(nums[i]==2){
//                 two++;
//             }
//         }
                                                         // o(n) better approach
        
//         for(int i=0; i<nums.size(); i++){
//             if(zero!=0){
//                 nums[i]=0;
//                 zero--;
//             }
            
//             else if(one!=0){
//                 nums[i]=1;
//                 one--;
//             }
            
//             else if(two!=0){
//                 nums[i]=2;
//                 two--;
//             }
//         }
        int s=0, m=0, e=nums.size()-1;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[s],nums[m]);
                s++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[e],nums[m]);
                e--;
            }
        }
    } 
};