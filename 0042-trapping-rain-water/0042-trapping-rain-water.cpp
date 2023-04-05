class Solution {
public:
    
    int trap(vector<int>& height) {
//         int n = he.size();
//         // left greatest element array;
//         int maxi = INT_MIN;
//         vector<int> l;
//         for(int i=0; i<n; i++){
//             maxi = max(maxi,he[i]);
//             l.push_back(maxi);
//         }
//         // right greatest element array;
//         maxi = INT_MIN;
//         vector<int> r;
//         for(int i=n-1; i>=0; i--){
//             maxi = max(maxi,he[i]);
//             r.push_back(maxi);
//         }
//         reverse(begin(r),end(r));
        
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             // cout<<l[i]<<":"<<r[i]<<" ";
//             int min_he = min(l[i],r[i]);
//             ans += (min_he - he[i]);
//         }
//         // cout<<endl;
//         return ans;
        
        int ans = 0;
        int n = height.size();
        int maxi = 0;
        vector<int> left;  // it carrys maximum hieght at left of i
        vector<int> right; // it carrys maximum hieght at right of i
        for(int i=0; i<n; i++){ // for left maximum height
            maxi = max(maxi,height[i]);
            left.push_back(maxi);
        }
        maxi = 0;
        for(int i=n-1; i>=0; i--){ // for right maximum height
            maxi = max(maxi,height[i]);
            right.push_back(maxi);
        }
        // since we iterated elements from back in height so we reverse to get correct order
        reverse(begin(right), end(right));
        
        for(int i=0; i<n; i++){
            int min_he = min(left[i],right[i]); // since the till lowest heiht among left or right we
                                            // can store water [3 , 1, 5] we can store wat. upto 3 only
                                            
            int water = min_he - height[i]; // we can only get water of height that is left above the 
                                             // current height[i] from min_he
            if(water >= 0){ // water can never be negative so check
                ans += water;
            }
            
        }
        
        return ans;
    }
};