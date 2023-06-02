class UndergroundSystem {
public:
    map<string, vector<int>> mp1;
    map<int, pair<string,int>> mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]= {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string st = mp[id].first;
        int st_time = mp[id].second;
        mp.erase(id);
        string str = st + "-" + stationName;
        mp1[str].push_back(t-st_time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str = startStation + "-" + endStation;
        double ans = 0;
        for(auto i:mp1[str]){
            ans += i;
        }
        ans = ans/mp1[str].size();
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */