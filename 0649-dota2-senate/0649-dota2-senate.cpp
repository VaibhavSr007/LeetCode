class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> r;
        queue<int> d;
        int n = senate.size();
        for(int i=0; i<senate.size(); i++){
            if(senate[i] == 'R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        
        while(!r.empty() && !d.empty()){
            int x = r.front();
            int y = d.front();
            r.pop();
            d.pop();
            if(x < y){
                r.push(x+n);
            }
            else{
                d.push(y+n);
            }
        }
        
        if(!r.empty()){ return "Radiant";}
        return "Dire";
    }
};