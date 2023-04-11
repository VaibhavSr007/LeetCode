class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         int count =1;
//         vector<int> v; 
//         int ans=1;
//         if(nums.size()<=1){
//             return nums.size();
//         }
        
//         sort(nums.begin(),nums.end());
//         nums.erase(unique(nums.begin(),nums.end()),nums.end());
//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i]+1==nums[i+1]){
//                 count++;
//             }
//             else{
//                 count =1;
//             }
//             ans = max(ans,count);
//         }
        
//         return ans;
        
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
        
        sort(nums.begin(),nums.end());
        int ans = 0;
        int cnt = 0;
        if(nums.size() < 1){ return 0;}
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]+1 == nums[i+1]){
                cnt++;
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                ans = max(ans,cnt+1);
                cnt = 0;
            }
        }
        ans = max(ans,cnt+1);
        return ans;
    }
};