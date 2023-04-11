class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int ans = 0;
        // int cnt = 0;
        // if(nums.size() < 1){ return 0;}
        // for(int i=0; i<nums.size()-1; i++){
        //     if(nums[i]+1 == nums[i+1]){
        //         cnt++;
        //     }
        //     else if(nums[i] == nums[i+1]){
        //         continue;
        //     }
        //     else{
        //         ans = max(ans,cnt+1);
        //         cnt = 0;
        //     }
        // }
        // ans = max(ans,cnt+1);
        // return ans;
        
//         unordered_map<int,int> s;
//         int ans = 0;
//         int count  = 0;
//         int cur_num;
//         for(int i=0; i<nums.size(); i++){
//             s[nums[i]] = i;
//         }
        
//         for(int i=0; i<nums.size(); i++){
//             if(s.find(nums[i]-1) == s.end()){
//                 cur_num = nums[i];
//                 count = 1;
                
//                 while(s.find(cur_num+1) != s.end()){
//                     cur_num += 1;
//                     count++;
//                 }
//                 ans = max(ans,count);
//             }
//             // ans = max(ans,count);
//         }
//         return ans;
        
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){ // find a number smallest in its sequence
                int cnt = 1;
                int val = nums[i];
                while(s.find(val+1) != s.end()){
                    cnt++;
                    val += 1;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};