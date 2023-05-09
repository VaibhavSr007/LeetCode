class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        
        int x = nums.size();
        int y = nums[0].size();
        
        int st_row = 0;
        int st_col = 0;
        int en_row = x-1;
        int en_col = y-1;
        
        int count = 0;
        int tot = x*y;
        
        while(count<tot){
            for(int i=st_col; count<tot && i<=en_col; i++){
                ans.push_back(nums[st_row][i]);
                count++;
            }
            st_row++;
            
            for(int i=st_row; count<tot && i<=en_row; i++){
                ans.push_back(nums[i][en_col]);
                count++;
            }
            en_col--;
            
            for(int i=en_col; count<tot && i>=st_col; i--){
                ans.push_back(nums[en_row][i]);
                count++;
            }
            en_row--;
            
            for(int i=en_row; count<tot && i>=st_row; i--){
                ans.push_back(nums[i][st_col]);
                count++;
            }
            st_col++;
            
        }
        
        return ans;
        
        
    }
};