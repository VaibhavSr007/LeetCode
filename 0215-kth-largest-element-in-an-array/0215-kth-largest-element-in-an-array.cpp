class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end()); 
    //     int ans = nums[nums.size()-k];  // nlogn
    //     return ans;
        
        
        
        // for(int i=1; i<k; i++){
        //     int x = *max_element(nums.begin(),nums.end());
        //     nums.erase(remove(nums.begin(),nums.end(),x),nums.end());  // O(n) approx
        // }
        // return *max_element(nums.begin(),nums.end());
        
        
        
//         priority_queue<int> pq;
        
//         for(auto i:nums){
//             pq.push(i);
//         }
//                                               // O(n)
//         for(int i=1; i<k; i++){
//             pq.pop();
//         }
        
//         return pq.top();
        
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        
        for(int i=k; i<nums.size(); i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};