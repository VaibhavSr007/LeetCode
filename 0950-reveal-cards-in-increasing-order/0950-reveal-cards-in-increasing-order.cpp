class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), i = 0;
        vector<int> v(n,0);
        deque<int> dq;
        sort(deck.begin(),deck.end());
        for(int i=0; i<n; i++){
            dq.push_back(i);
        }
        
        
        while(!dq.empty()){
            int x = dq.front();
            dq.pop_front();
            v[x] = deck[i++];
            if(!dq.empty()){
                int y = dq.front();
                dq.pop_front();
                dq.push_back(y);
            }
        }
        
        
        return v;
    }
};