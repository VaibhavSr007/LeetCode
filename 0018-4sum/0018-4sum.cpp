class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> v1;
        if(nums.size()<1){
            return v1;
        }
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){// vital step to move i's value to next non-duplicate
                    continue;
            }
            for(int j=i+1; j<nums.size(); j++){
                long long rem = long(target)-nums[i]-nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    if(nums[left]+nums[right]==rem){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.insert(v);
                        left++;
                        right--;
                    }
                    else if(nums[left]+nums[right] < rem){
                        left++;
                    }
                    else if(nums[left]+nums[right] > rem){
                        right--;
                    }
                }
            }
        }
       
        for(auto i:ans){
            v1.push_back(i);
        }
        return v1; 
    }
};

// for(int k=j+1; k<nums.size()-1; k++){
//                     for(int l=k+1; l<nums.size(); l++){
//                         if(nums[l] + nums[k] + nums[i] + nums[j] == target){
//                             v.push_back(nums[i]);
//                             v.push_back(nums[j]);
//                             v.push_back(nums[k]);
//                             v.push_back(nums[l]);
//                             ans.insert(v);
//                             v.clear();
//                         }
//                     }
//                 }