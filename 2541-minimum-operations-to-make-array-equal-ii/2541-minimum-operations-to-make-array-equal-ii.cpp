class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0){
            for(int i=0; i<nums1.size(); i++){
                if(nums1[i]!=nums2[i]){
                    return -1;
                }
            }
            return 0;
        }
        
        long long in =0;
        long long dc =0;
        for(int i=0; i<nums1.size(); i++){
            int diff = nums1[i]-nums2[i];
            if(diff%k!=0){
                return -1;
            }
            else{
                if(diff>=0){
                    in += diff/k;
                }
                else{
                    dc -= diff/k;
                }
            }
        }
        if(in!=dc){
            return -1;
        }
        return in;
    }
};