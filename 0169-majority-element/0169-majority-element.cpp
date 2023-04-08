class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         map<int,int> mp;
//         int n = nums.size();
//         int max = n/2;
//         int ans = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it=mp.begin(); it!=mp.end(); it++){
//             if(it->second > max){
//                 ans = it->first;
//                 break;
//             }
//         }
//         return ans;
        
        int count = 0;
        int ele = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            
            if(nums[i] == ele){
                count++;
            }
            else if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};