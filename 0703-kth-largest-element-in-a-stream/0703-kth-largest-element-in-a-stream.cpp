class KthLargest {
public:
    int idx;
    // priority_queue<int> pq;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums){
            // pq.push(i);
            v.push_back(i);
        }
        sort(begin(v),end(v));
        idx = k;
    }
    
    int add(int val) {
        // vector<int> v;
        // int cnt = 0;
        // pq.push(val);
        // while(cnt!=idx-1){
        //     cnt++;
        //     v.push_back(pq.top());  
        //     pq.pop();
        // }
        // int ans = pq.top();
        // for(auto i:v){
        //     pq.push(i);
        // }
        // return ans; 
        
        int index = v.size();
        for(int i=0; i<v.size(); i++){
            if(v[i] > val){
                index = i;
                break;
            }
        }
        v.insert(v.begin()+index,val);
        return v[v.size()-idx];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */