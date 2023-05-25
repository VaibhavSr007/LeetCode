class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        for(int i=0; i<nums1.size(); i++){
            v.push_back({nums2[i],nums1[i]});   
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        // for(auto i:v){
        //     cout<<i[0]<<":"<<i[1]<<" ";
        // }
        // cout<<endl;
        
        long long maxi = INT_MIN, sum  = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<k-1; i++){
            sum += v[i][1];
            pq.push(v[i][1]);
        }
        
        for(int i=k-1; i<v.size(); i++){
            sum += v[i][1];
            pq.push(v[i][1]);
            maxi = max(maxi, sum*v[i][0]);
            sum -= pq.top();
            pq.pop();
        }
        return maxi;
    }
};