class Solution {
public:
    static bool cmp(pair<int,char> &a, pair<int,char> &b){
        if(a.first > b.first || a.first == b.first && a.second < b.second){
            return false;
        }
        return true;
    }

    string frequencySort(string s) {
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        
        vector<pair<int,char>> v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.rbegin(), v.rend(), cmp);
        
        string ans = "";
        
        for(auto i:v){
            for(int x=0; x<i.first; x++){
                ans += i.second;
            }
        }
        
        return ans;
    }
};