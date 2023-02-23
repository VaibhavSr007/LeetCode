class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a=0;
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == nums[i+1]){
        //         a = nums[i];                 not optimized approach  due to sort
        //         break;
        //     }
        // }
        // return a;
        
        
        int n = nums.size();
        
//         vector<int> v(n,0);
        
//         for(int i=0; i<nums.size(); i++){
//             v[nums[i]]++;
//         }
        
//         for(int i=1; i<v.size(); i++){
//             if(v[i]>1){
//                 a = i;
//             }
//         }
//         return a;
        
        set<int> s;
        for(auto i:nums){
            if(s.find(i)==s.end()){
                s.insert(i);
            }
            else{
                return i;
            }
        }
        return 0;
    }
};