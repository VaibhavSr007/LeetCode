class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        long long ans = 1;
        sort(nums.rbegin(), nums.rend());
        bool chk = true;
        int cnt = 0, zero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                cnt++;
            }
            else if(nums[i] > 0){
                ans *= nums[i];
                chk = false;
            }
            else{
                zero++;
            }
        }
        
        
        if(zero == 0 && cnt == 0 && !chk){
            return ans;
        }
        else if((cnt == 0 && chk && zero != 0) || (cnt==1 && chk && zero != 0)){
            return 0;
        }
        
        if(cnt > 1){
            if(cnt%2==0){
            int i = nums.size()-1;
                while(cnt!=0){
                    ans *= nums[i];
                    i--;
                    cnt--;
                }
            }
            else{
                int i = nums.size()-1;
                while(cnt!=1){
                    ans *= nums[i];
                    i--;
                    cnt--;
                }
            }
        }
        return ans;
    }
};