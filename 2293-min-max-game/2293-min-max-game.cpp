class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> v;
        bool chk = true;
        for(int i=0; i<nums.size(); i+=2){
            int val;
            if(chk){
                val = min(nums[i],nums[i+1]);
            }
            else{
                val = max(nums[i],nums[i+1]);
            }
            v.push_back(val);
            chk = !chk;
        }
        
        while(v.size() != 1){
            vector<int> res;
            bool chk = true;
            for(int i=0; i<v.size(); i+=2){
                int val;
                if(chk){
                    val = min(v[i],v[i+1]);
                }
                else{
                    val = max(v[i],v[i+1]);
                }
                res.push_back(val);
                chk = !chk;
            }
            
            v = res;
        }
        return v[0];
    }
};