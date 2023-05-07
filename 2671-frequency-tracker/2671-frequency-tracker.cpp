class FrequencyTracker {
public:
    map<int,int> s;
    map<int,int> mp;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number) != mp.end()){
            s[mp[number]]--;
            if(s[mp[number]] == 0){
                s.erase(mp[number]);
            }
        }
        
        mp[number]++;
        s[mp[number]]++;
    }
    
    void deleteOne(int number) {
        
        if(mp.find(number) == mp.end()){
            return ;
        }
        if(mp.find(number) != mp.end()){
            s[mp[number]]--;
            if(s[mp[number]] == 0){
                s.erase(mp[number]);
            }
        }
        mp[number]--;
        if(mp[number] == 0){
            mp.erase(number);
        }
        else{
           s[mp[number]]++; 
        }
        
    }
    
    bool hasFrequency(int frequency) {
        if(s.find(frequency) != s.end()){
            return  true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */