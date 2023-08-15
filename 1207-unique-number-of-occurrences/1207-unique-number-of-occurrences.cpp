class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        set<int> s;
        for(auto i:arr){
            mp[i]++;
        }
        
        for(auto i:mp){
            if(s.find(i.second) == s.end()){
                s.insert(i.second);
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};