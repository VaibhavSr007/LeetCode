class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int cnt = 0;
        // int ans = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             int cnt = 0;
//             for(int j=i; j<nums.size(); j++){
//                 if(nums[j]%2 != 0){
//                     cnt++;
//                 }
                
//                 if(cnt == k){             //brute force
//                     ans++;
//                 }
//                 if(cnt > k){
//                     break;
//                 }
//             }
//         }
        
//         int i=0, j=0, temp=0;
//         while(j<nums.size()){
//             if(nums[j]%2 != 0){
//                 cnt++;
//                 temp  = 0;
//             }
            
//             j++;
            
//             while(cnt == k){
//                 if(nums[i]%2 != 0){
//                     cnt--;
//                 }
//                 i++;
//                 cout<<i<<" ";
//                 temp++;
//             }
//             ans += temp;
            
//             // cout<<cnt<<" ";
//         }
//         cout<<endl;
//         return ans;
        
        map<int,int> mp;
        int sum = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]%2;
            if(sum == k){
                ans++;
            }
            
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};