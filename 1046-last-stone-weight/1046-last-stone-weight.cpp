class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        if(stones.size() == 1){ return stones[0];}
        priority_queue<int> pq;
        
        for(auto i:stones){
            pq.push(i);
        }
        
        while(pq.size() != 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            // cout<<x<<":"<<y<<" ";
            if(x != y){
                pq.push(x-y);
            }
            
            if(pq.size() == 0){
                return 0;
            }
        }
        
        return pq.top();
    }
};