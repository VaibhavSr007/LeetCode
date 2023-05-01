class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = *max_element(salary.begin(), salary.end());
        int mini = *min_element(salary.begin(), salary.end());
        
        double sum = 0;
        for(auto i:salary){
            if(i==maxi){
                continue;
            }
            else if(i == mini){
                continue;
            }
            else{
                sum += i;
            }
        }
        
        double ans = sum/(salary.size()-2);
        return ans;
    }
};