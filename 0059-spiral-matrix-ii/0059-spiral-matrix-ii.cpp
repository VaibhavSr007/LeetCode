class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v (n, vector<int>(n,0));
        int stcol = 0, strow = 0;
        int encol = n-1, enrow = n-1;
        int val = 1;
        
        for(int i=1; i<2*n; i++){
            if(i%4==1){
                for(int j=stcol; j<=encol; j++){
                    v[strow][j] = val++;
                }
                strow++;
            }
            
            if(i%4 == 2){
                for(int j=strow; j<=enrow; j++){
                    v[j][encol] = val++;
                }
                encol--;
            }
            
            if(i%4 == 3){
                for(int j=encol; j>=stcol; j--){
                    v[enrow][j] = val++;
                }
                enrow--;
            }
            
            if(i%4 == 0){
                for(int j=enrow; j>=strow; j--){
                    v[j][stcol] = val++;
                }
                stcol++;
            }
        }
        
        return v;
    }
};