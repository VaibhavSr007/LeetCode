class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        map<char,int> mp;
        for(auto i:jewels){
            mp[i]++;
        }
        
        for(auto i:stones){
            if(mp.find(i) != mp.end()){
                ans++;
            }
        }
        return ans;
    }
};