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
        
        
        // Moore's voting algorithm
        int cnt = 0;
        int ele = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele){ // if an ele comes again increase its cnt
                cnt++;
            }
            else if(cnt == 0){ // if cnt has become 0 this means no element is in majority therefore we 
                cnt = 1;       // assume new element as our majority ele and make cnt 1 
                ele = nums[i];
            }
            else{   // if another element comes other than assumed majority ele we reduce the cnt of 
                cnt--;  // assumed majority ele
            }
        }
        return ele;
    }
};