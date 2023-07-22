class Solution {
public:
    vector<vector<int>> dir = {{2,-1}, {2,1}, {-2,-1}, {-2,1}, {1,-2}, {1,2}, {-1,-2},{-1,2}};
    
    double solve(int i, int j, int k, map<string,double> &dp, int n){
        
        if(k == 0){
            return 1.0;
        }
        
        string s = to_string(i) + "+" + to_string(j) + "+" + to_string(k);
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        
        double ans = 0;
        for(auto d:dir){
            int x = d[0] + i;
            int y = d[1] + j;
            
            if(x>=0 && y>=0 && x<n && y<n){
                ans += ((solve(x,y,k-1,dp,n))/8.0);
            }
        }
        
        return dp[s] = ans;
        
    }
    double knightProbability(int n, int k, int row, int col) {
        
        
        map<string,double> dp;
        
        return solve(row, col,k, dp , n);
    }
};