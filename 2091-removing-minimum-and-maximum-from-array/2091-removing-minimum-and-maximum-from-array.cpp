class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), a=0, b=0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                a = i;
            }
            
            if(nums[i] < mini){
                mini = nums[i];
                b = i;
            }
        }
        
        int x = (n-max(a,b)) + (min(a,b)-0+1);
        int y = max(a,b)+1;
        int z = n-min(a,b);
        
        // cout<<a<<" "<<b<<endl;
        // cout<<x<<":"<<y<<":"<<z<<endl;
        return min(x,min(y,z));
    }
};