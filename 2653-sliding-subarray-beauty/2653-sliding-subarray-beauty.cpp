class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> fre(51,0);
        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j] < 0){
                fre[abs(nums[j])]++;
            }
            
            if(j-i+1 == k){
                int cnt = 0;
                
                for(int k=50; k>=1; k--){
                    cnt += fre[k];
                    if(cnt >= x){
                        ans.push_back(-k);
                        break;
                    }
                }
                if(cnt < x){
                    ans.push_back(0);
                }
                if(nums[i] < 0){
                    fre[abs(nums[i])]--;
                }
                i++;
            }
            j++;
        }
        
        return ans;
        
    }
};