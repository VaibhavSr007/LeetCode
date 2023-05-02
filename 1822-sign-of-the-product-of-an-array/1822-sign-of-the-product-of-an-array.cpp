class Solution {
public:
    int arraySign(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto i:nums){
            if(i<0){
                mp[-1]++;
            }
            else if(i>0){
                mp[1]++;
            }
            else{
                mp[0]++;
            }
        }
        
        if(mp.find(0) != mp.end()){
            return 0;
        }
        if(mp.find(-1) != mp.end()){
            if(mp[-1] % 2 != 0){
                return -1;
            }
        }
        
        return 1;
    }
};