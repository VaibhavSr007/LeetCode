class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size();
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(i==j){
                    ans += mat[i][j];
                }
                else if(i+j == n-1){
                    ans += mat[i][j];
                }
                
            }
        }
        return ans;
    }
};