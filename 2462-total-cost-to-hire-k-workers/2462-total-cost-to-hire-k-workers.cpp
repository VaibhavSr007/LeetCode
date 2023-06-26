class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<pair<int,char>,vector<pair<int,char>>, greater<pair<int,char>>> pq;
        
        if(2*candidates > costs.size()){
            sort(costs.begin(),costs.end());
            for(int i=0; i<k; i++){
                ans += costs[i];
            }
            return ans;
        }
        
        
        
        // cout<<costs.size()<<" ";
        for(int i=0; i<candidates; i++){
            pq.push({costs[i],'l'});
        }
        int idx = costs.size()-1;
        for(int i=0; i<candidates; i++){
            pq.push({costs[idx--],'r'});
        }
        
        int i = candidates-1, j=costs.size()-candidates;
        int cnt = 0;
        while(i<j-1){
            auto temp = pq.top();
            pq.pop();
            cnt++;
            if(temp.second == 'l'){
                ans += temp.first;
                i++;
                pq.push({costs[i],'l'});
            }
            else if(temp.second == 'r'){
                ans += temp.first;
                j--;
                pq.push({costs[j],'r'});
            }
           
            if(cnt==k){
                break;
            }
        }
        cout<<cnt<<" ";
        while(cnt != k){
            ans += pq.top().first;
            pq.pop();
            cnt++;
        }
        return ans;
    }
};