class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        long long sum = 0;
        int n=nums.size(), i = 0, div = 2*k + 1;;
        bool chk = true;
        while(i<n){
            if(i-k >= 0 && i+k < n){
                if(i-k==0){
                    int x = i+k, y = i;
                    while(y <= x){
                        sum += nums[y];
                        y++;
                    }
                    chk = false;
                }
                else{
                    sum -= nums[i-k-1];
                    sum += nums[i+k];
                }
                int val = sum/div;
                ans.push_back(val);
            }
            else{
                sum += nums[i];
                ans.push_back(-1);
            }
            i++;
        }
        
        return ans;
    }
};