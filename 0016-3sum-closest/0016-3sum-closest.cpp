class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int ans;
        vector<int> v;
        
        for(int i=0; i<nums.size()-1; i++){
            int s = i+1;
            int e = nums.size()-1;
            
            while(s<e){
                int val = nums[i] + nums[s] + nums[e];
                if(val<=target){
                    v.push_back(val);
                    s++;
                }
                else{
                    v.push_back(val);
                    e--;
                }
            }
        }
        
        sort(v.begin(),v.end());
        
        int i = 0;
        while(i<v.size()){
            if(abs(v[i]-target) < mini){
                mini = abs(v[i]-target);
                maxi = v[i];
            }
            i++;
        }
        
        return maxi;
    }
};