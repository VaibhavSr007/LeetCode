class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> vec;
//         vector<int> v;
//         set<vector<int>> ans;
//         for(int i=0; i<nums.size(); i++){
//             int l = i+1;
//             int e = nums.size()-1;
            
//             if(i>0 && nums[i]==nums[i-1]){// vital step to move i's value to next non-duplicate
//                     continue;
//             }
            
//             while(l<e){
//                 if(nums[l]+nums[e]+nums[i]==0){
//                     vector<int> v;
//                     v.push_back(nums[i]);
//                     v.push_back(nums[l]);
//                     v.push_back(nums[e]);
//                     ans.insert(v);
//                     l++;
//                     e--;
//                 }
//                 else if(nums[l]+nums[e]+nums[i]<0){
//                     l++;
//                 }
//                 else{
//                     e--;
//                 }
//             }
//         }
//         for(auto i:ans){
//             vec.push_back(i);
//         }
        
//         return vec;
        
        sort(nums.begin(),nums.end());
        set<vector<int>> se;
        for(int i=0; i<nums.size(); i++){
            int s = i+1;
            int e = nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(s<e){
                if(nums[i]+nums[s]+nums[e] == 0){
                    vector<int> v = {nums[i], nums[s], nums[e]};
                    se.insert(v);
                    s++;
                    e--;
                }
                else if(nums[i]+nums[s]+nums[e] < 0){
                    s++;
                }
                else if(nums[i]+nums[s]+nums[e] > 0){
                    e--;
                }
            }
        }
        vector<vector<int>> vc(se.begin(),se.end());
        return vc;
    }
};