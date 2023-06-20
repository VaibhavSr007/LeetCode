class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int ans = 0, sum =0;
        int i=0, j=0;
        while(i<nums.size()){
            if(i-j < k){
                
            }
            else{
                int val = sum/k;
                if(val >= threshold){
                    // cout<<sum<<" ";
                    ans++;
                }
                sum -= nums[j];
                j++;
            }
            sum += nums[i];
            i++;
        }
        int val = sum/k;
        if(val >= threshold){
            ans++;
        }
        
        return ans;
    }
};