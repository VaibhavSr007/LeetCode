class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n= nums.size();
        // int f = 0;
        // int s = (nums.size()+1)/2;
        // while(s<n){
        //     if(2*nums[f] <= nums[s]){
        //         f++;
        //     }
        //     s++;
        // }
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(2*nums[i]<=nums[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return f*2;
        
        sort(begin(nums),end(nums));
        int i = 0;
        int m = (nums.size()+1)/2;
        while(m<nums.size() && i<m){
            if(2*nums[i] <= nums[m]){
                m++;
                i++;
            }
            else{
                m++;
            }
        }
        
        return i*2;
    }
};