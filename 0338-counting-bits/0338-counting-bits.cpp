class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++){
            int copy = i, cnt = 0;
            
            while(copy != 0){
                if(copy&1 == 1){
                    cnt++;
                }
                copy /= 2;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};