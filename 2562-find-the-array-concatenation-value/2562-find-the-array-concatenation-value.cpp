class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        
        int i=0;
        int j=nums.size()-1;
        
        while(i<j){
            string x = to_string(nums[j]);
            string y = to_string(nums[i]);
            reverse(begin(x),end(x));
            while(x!=""){
                char rem =x.back();
                x.pop_back();
                y.push_back(rem);
            }
            i++;
            j--;
            ans +=stoll(y);
        }
        
        if(nums.size()%2!=0){
            ans += nums[nums.size()/2];
        }
        return ans;
        
    }
};