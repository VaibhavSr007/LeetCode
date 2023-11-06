class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> v;
    
    SeatManager(int n) {
        for(int i=1; i<=n; i++){
            pq.push(i);
        }
        
        for(int i=0; i<=n; i++){
            v.push_back(0);
        }
        
    }
    
    int reserve() {
        int top = pq.top();
        // v[top] = 1;
        pq.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        // v[seatNumber] = 0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */