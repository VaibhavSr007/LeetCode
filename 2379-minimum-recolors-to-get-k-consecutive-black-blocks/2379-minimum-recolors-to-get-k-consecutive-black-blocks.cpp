class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, cnt = 0;
        int i=0, j=0;
        while(j< blocks.length()){
            if(j-i < k){
                if(blocks[j] == 'W'){
                    cnt++;
                }
            }
            else{
                ans = min(cnt, ans);
                if(blocks[j] == 'W'){
                    cnt++;
                }
                if(blocks[i] == 'W'){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        ans = min(cnt, ans);
        return ans;
    }
};