class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> ans;
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int n = nums1.size(), m = nums2.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int sum = nums1[i]+nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else if(sum < pq.top().first){
                     pq.pop();
                     pq.push({sum, {nums1[i], nums2[j]}});
                }
                else{
                    break;
                }
            } 
        }
        
        
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            ans.push_back({v.second.first,v.second.second});
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};