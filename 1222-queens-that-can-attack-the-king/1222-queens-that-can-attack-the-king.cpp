class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {         
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(auto i:queens){
            s.insert(i);
        }
        
        // up
        for(int i=king[0]; i>=0; i--){
            if(s.find({i,king[1]}) != s.end()){
                ans.push_back({i,king[1]});
                break;
            }
        }
        // down
        for(int i=king[0]; i<8; i++){
            if(s.find({i,king[1]}) != s.end()){
                ans.push_back({i,king[1]});
                break;
            }
        }
        // left
        for(int i=king[1]; i>=0; i--){
            if(s.find({king[0],i}) != s.end()){
                ans.push_back({king[0],i});
                break;
            }
        }
        // right
        for(int i=king[1]; i<8; i++){
            if(s.find({king[0],i}) != s.end()){
                ans.push_back({king[0],i});
                break;
            }
        }
        
        // left top
        int i=king[0]-1, j=king[1]-1;
        while(i>=0 && j>=0){
            if(s.find({i,j}) != s.end()){
                ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
        // right top
        i=king[0]-1, j=king[1]+1;
        while(i>=0 && j<8){
            if(s.find({i,j}) != s.end()){
                ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
        // right bottom
        i=king[0]+1, j=king[1]+1;
        while(i<8 && j<8){
            if(s.find({i,j}) != s.end()){
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        // left bottom
        i=king[0]+1, j=king[1]-1;
        while(i<8 && j<8){
            if(s.find({i,j}) != s.end()){
                ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        
        return ans;
    }
};