class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//         vector<vector<int>> v(matrix);
        
//         for(int i=0; i<v.size(); i++){        // this approach uses the xtra space 
//             for(int j=0; j<v[i].size(); j++){
//                 matrix[i][j] = v[v.size()-1-j][i];
//             }
//         }
        
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<i; j++){              // taking transpose of matrix
                    swap(matrix[i][j],matrix[j][i]);
                }
            }          // this is more space optimized approach no xtra space needed
        
            for(int i=0; i<matrix.size(); i++){
                reverse(matrix[i].begin(),matrix[i].end());  // reverse each row of                                                                matrix to get desired ans
            }
    }
};