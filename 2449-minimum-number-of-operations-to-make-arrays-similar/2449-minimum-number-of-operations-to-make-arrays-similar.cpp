class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        vector<int> ev;
        vector<int> od;
        vector<int> ev_tar;
        vector<int> od_tar;
        
        for(auto i:nums){
            if(i%2==0){
                ev.push_back(i);
            }
            else{
                od.push_back(i);
            }
        }
        for(auto i:target){
            if(i%2==0){
                ev_tar.push_back(i);
            }
            else{
                od_tar.push_back(i);
            }
        }
        
        sort(begin(ev),end(ev));
        sort(begin(od),end(od));
        sort(begin(ev_tar),end(ev_tar));
        sort(begin(od_tar),end(od_tar));
        
        for(int i=0; i<ev.size(); i++){
            if(ev[i]-ev_tar[i] > 0){
                ans += (ev[i]-ev_tar[i])/2;
            }
        }
        for(int i=0; i<od.size(); i++){
            if(od[i]-od_tar[i] > 0){
                ans += (od[i]-od_tar[i])/2;
            }
        }
        return ans;
    }
};