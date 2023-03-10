class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            int sum = 0;
            vector<int> v;
            v.push_back(sum);
            for(int j=0; j<matrix[i].size(); j++){
                sum += matrix[i][j];
                v.push_back(sum);
            }
            pre.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1; i<=row2; i++){
            ans += (pre[i][col2+1]-pre[i][col1]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */