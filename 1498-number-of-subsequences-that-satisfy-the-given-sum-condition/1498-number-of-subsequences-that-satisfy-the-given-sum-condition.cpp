class Solution {
public:
    
    long long power( long long n, long long mod, long long base){
        long long ans = 1;
        
        while(n!=0){
            if(n%2==0){
                n = n/2;
                base = (base*base)%mod;
            }
            else{
                ans = (ans*base)%mod;
                n--;
            }
        }
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1000000007;
        int ans = 0;
        int j= nums.size()-1, i=0;
        
        while(i<=j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                long long val = power(j-i, mod, 2);
                ans = (ans + val)%mod;
                i++;
            }
        }
        return ans;
    }
};