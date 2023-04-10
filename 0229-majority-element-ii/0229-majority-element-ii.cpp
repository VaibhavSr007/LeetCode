class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int n = nums.size();
//         int max = n/3;
//         vector<int> ans;
        
//         for(int i=0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it=mp.begin(); it!=mp.end(); it++){
//             if(it->second > max){
//                 ans.push_back(it->first);
//             }
//         }
//         return ans;
        
        vector<int> ans;
        int ele1, ele2;
        int cnt1=0, cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto i:nums){
            if(ele1 == i){
                cnt1++;
            }
            if(ele2 == i){
                cnt2++;
            } 
        }
        
        if(cnt1 > nums.size()/3){
            ans.push_back(ele1);
        }
        if(cnt2 > nums.size()/3){
            ans.push_back(ele2);
        }
        return ans;
    }
};