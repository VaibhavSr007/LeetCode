class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int i=0, j=0, res = 0, cnt = k;
        
        // for true
        while(j < ans.length()){
            if(ans[j] == 'F'){
                cnt--;
            } 
            
            j++;
            while(cnt < 0){
                if(ans[i] == 'F'){
                    cnt++;
                }
                i++;
            }
            
            res = max(res, j-i);
        }
        
        
        i=0, j=0, cnt = k;
        while(j < ans.length()){
            if(ans[j] == 'T'){
                cnt--;
            } 
            
            j++;
            while(cnt < 0){
                if(ans[i] == 'T'){
                    cnt++;
                }
                i++;
            }
            
            res = max(res, j-i);
        }
        
        return res;
    }
};