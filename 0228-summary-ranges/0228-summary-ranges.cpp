class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int cnt = 0, i=0, j=0;
        vector<string> ans;
        if(nums.size()==0){
            return {};
        }else if(nums.size()==1){
            return {to_string(nums[0])};
        }
        
        while(j<nums.size()-1){
            if(nums[j] == nums[j+1]-1){
                j++;
            }
            else{
                if(j-i == 0){
                    string s = to_string(nums[j]);
                    ans.push_back(s);
                }
                else{
                    string s = to_string(nums[j]);
                    string u = to_string(nums[i]);
                    string t = u + "->" + s;
                    ans.push_back(t);
                }
                j+=1;
                i=j;
            }
        }
        
        if(j-i == 0){
            string s = to_string(nums[j]);
            ans.push_back(s);
        }
        else{
            string s = to_string(nums[j]);
            string u = to_string(nums[i]);
            string t = u + "->" + s;
            ans.push_back(t);
        }
        
        return ans;
    }
};