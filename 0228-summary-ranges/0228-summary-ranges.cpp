class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==1){
            return {to_string(nums[0])};
        }
        else if(nums.size()==0){ return {};
                               }
        int cnt = 1;
        int st = nums[0];
        int prev = nums[0];
        vector<string> ans;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                cnt++;
                prev = nums[i];
            }
            else{
                string val = "";
                if(cnt == 1)
                    val = to_string(st);
                else
                    val = to_string(st)+"->"+to_string(prev);
                
                ans.push_back(val);
                prev = nums[i];
                st = nums[i];
                cnt = 1;
            }
        }
        string val = "";
        if(cnt == 1)
            val = to_string(st);
        else
            val = to_string(st)+"->"+to_string(prev);

        ans.push_back(val);
        return ans;
    }
};