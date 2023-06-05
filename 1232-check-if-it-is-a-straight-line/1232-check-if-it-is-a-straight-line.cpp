class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set<float> s;
        
        for(int i=0; i<coordinates.size(); i++){
            for(int j=i+1; j<coordinates.size(); j++){
                float x = abs(coordinates[i][0] - coordinates[j][0]);
                float y = abs(coordinates[i][1] - coordinates[j][1]);
                float val = (x/y);
                // cout<<val<<":";
                s.insert(val);
            }
            // cout<<" ";
        }
        
        if(s.size() == 1){
            return true;
        }
        return false;
    }
};