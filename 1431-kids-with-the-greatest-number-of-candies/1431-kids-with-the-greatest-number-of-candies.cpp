class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = INT_MIN;
        vector<bool> ans;
        for(auto i:candies){
            maxi = max(i,maxi);
        }
        
        for(auto i:candies){
            if(i+extraCandies >= maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};