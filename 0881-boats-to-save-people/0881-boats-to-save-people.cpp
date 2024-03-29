class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(begin(people),end(people));
        int i=0;
        int j = people.size()-1;
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
                ans++;
            }
            else{
                j--;
                ans++;
            }
        }
        return ans;
    }
};