class Solution {
public:
    bool all_neg(vector<int> nums){
        for(auto i:nums){
            if(i>=0){
                return false;
            }
        }
        return true;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<A.size(); i++){
            sum += A[i];
            maxi = max(maxi,sum);
            if(sum < 0){
                sum  = 0;
            }
        }
        
        // now finding min sum subaaray and subtract it from the total to get maximum subaaray in circle
        int mini = INT_MAX;
        sum = INT_MAX;
        
        for(auto i:A){
            if(sum>0){
                sum = i;
            }
            else{
                sum += i;
            }
            mini = min(mini,sum);
        }
        
        int   tot = 0;
        for(auto i:A){
            tot += i;
        }
        if(all_neg(A)){
            int ans = *max_element(begin(A),end(A));
            return ans;
        }
        int ans = max(maxi,tot-mini);
        return ans;
    }
};