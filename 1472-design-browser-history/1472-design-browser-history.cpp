class BrowserHistory {
public:
    vector<string> v;
    int idx = -1;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        idx = 0;
    }
    
    void visit(string url) {
        if(idx == -1){
            v.push_back(url);
            idx = v.size()-1;
        }
        else{
            while(v.size()!=idx+1){
                v.pop_back();
            } 
            v.push_back(url);
            idx = v.size()-1;
        }
    }
    
    string back(int steps) {
        
            if(idx-steps >= 0){
                idx = idx-steps;
                return v[idx];
            }
            idx = 0;
            return v[idx];

    }
    
    string forward(int steps) {
        
            if(v.size() > idx+steps){
                idx = idx+steps;
                return v[idx];
            }
            idx = v.size()-1;
            return v[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */