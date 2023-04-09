class Solution {
public:
    bool isPrime(int n){
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                if(i==j){
                    if(isPrime(nums[i][j])){
                        ans = max(ans,nums[i][j]);
                    }
                }
                else if(j == nums[i].size()-i-1){
                    if(isPrime(nums[i][j])){
                        ans = max(ans,nums[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};