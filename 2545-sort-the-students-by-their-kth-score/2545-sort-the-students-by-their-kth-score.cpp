class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second > b.second){
            return true;
        }
        return false;
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(int i=0; i<score.size(); i++){
            mp[i] = score[i][k];
        }
        vector<pair<int,int>> v;
        for(auto i:mp){
            v.push_back({i.first,i.second});
        }
        sort(begin(v),end(v),cmp);        
        for(auto i:v){
            ans.push_back(score[i.first]);
        }
        return ans;
    }
};