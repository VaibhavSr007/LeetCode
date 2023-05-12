class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans  = INT_MIN, tot = 0, n = cardPoints.size();
        int sum = 0;
        for(auto i: cardPoints){
            tot += i;
        }
        
        if(n == k){
            return tot;
        }
        int i=0,j=0;
        while(j<n){
            sum += cardPoints[j];
            if(j-i+1 == n-k){
                ans = max(ans,tot-sum);
                sum -= cardPoints[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};