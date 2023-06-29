class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n,INT_MIN), post(n,INT_MIN);
        int maxi = INT_MIN;
        
        for(int i=1; i<height.size(); i++){
            maxi = max(height[i-1],maxi);
            pre[i] = maxi;
        }
        
        maxi = INT_MIN;
        for(int i=height.size()-2; i>=0; i--){
            maxi = max(height[i+1],maxi);
            post[i] = maxi;
        }
        
        
        
        int ans = 0;

        for(int i=0; i<n; i++){
            if(pre[i] > height[i] && post[i] > height[i]){
                int hgt = min(pre[i], post[i]);
                ans += (hgt - height[i]);
            }
        }
        
        return ans;
    }
};