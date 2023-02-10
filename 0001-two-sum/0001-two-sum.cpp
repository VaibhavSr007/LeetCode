class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j]==target){
        //             nums.clear();
        //             nums.push_back(i);            //  brute force
        //             nums.push_back(j);
        //         }
        //     }
        // }
        // return nums;
        
        unordered_map<int,int> mp;
        vector<int> v;
        
        for(int i=0; i< nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                v.push_back(i);
                v.push_back(mp[target-nums[i]]);
                break;
            }
            
            mp[nums[i]] = i;
            
        }
        return v;
        
        
        // sort(nums.begin(),nums.end());
        // int i = 0;
        // int j = nums.size()-1;
        // vector<int> v;
        // while(i<j){
        //     if((nums[i]+nums[j])==target){
        //         v.push_back(i);
        //         v.push_back(j);
        //         break;
        //     }
        //     else if((nums[i]+nums[j])<target){
        //         ++i;
        //     }
        //     else if((nums[i]+nums[j])>target){
        //         j--;
        //     }
        // }
        // return v;
        
        // map<int,int> mp;
//         vector<int> v;
//         for(int i=0; i<nums.size(); i++){
//             mp[nums[i]] = i;
//         }
        
//         for(int i=0; i<nums.size(); i++){
//             if(mp.find(target-nums[i]) != mp.end()){
//                 if(i!=mp[target-nums[i]]){
//                     v.push_back(i);
//                     v.push_back(mp[target-nums[i]]);
//                     break;
//                 }
//             }
//             // mp[nums[i]] = i;
//         }
//         return v;
     }
};

