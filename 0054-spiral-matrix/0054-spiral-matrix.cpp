class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> v;
        int col = 0, row = 0, cnt = 0;
        int enRow = matrix.size()-1, enCol=matrix[0].size()-1;
        int tot = (enRow+1)*(enCol+1);
        
        while(cnt < tot){
            
            for(int i=col; i<=enCol && cnt < tot; i++){
                v.push_back(matrix[row][i]);
                cnt++;
            }
            row++;
            
            for(int i=row; i<=enRow && cnt < tot; i++){
                v.push_back(matrix[i][enCol]);
                cnt++;
            }
            enCol--;
            
            for(int i=enCol; i>=col && cnt < tot; i--){
                v.push_back(matrix[enRow][i]);
                cnt++;
            }
            enRow--;
            
            for(int i=enRow; i>=row && cnt < tot; i--){
                v.push_back(matrix[i][col]);
                cnt++;
            }
            col++;
        }
        
        return v;
    }
};