class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long ans = INT_MAX;
        if(n==1){
            return 0;
        }
        
        
        // into 0
        // to right
        long long cnt = 0;
        bool chk = true;
        for(int i=n/2; i<n; i++){
            if(chk && s[i] == '1'){
                chk = false;
                cnt += n-i;
            }
            else if(!chk && s[i] == '0'){
                chk = true;
                cnt += n-i;
            }
        }
        
        // to left
        
        chk = true;
        for(int i=(n/2)-1; i>=0; i--){
            if(chk && s[i] == '1'){
                chk = false;
                cnt += i+1;
            }
            else if(!chk && s[i] == '0'){
                chk = true;
                cnt += i+1;
            }
        }
        cout<<cnt<<endl;
        
        
        
        // into 1 *************************************
        
        // to right
        long long cnt1 = 0;
        chk = true;
        for(int i=(n/2); i<n; i++){
            if(chk && s[i] == '0'){
                chk = false;
                cnt1 += n-i;
            }
            else if(!chk && s[i] == '1'){
                chk = true;
                cnt1 += n-i;
            }
        }
        
        // left
        chk = true;
        for(int i=(n/2)-1; i>=0; i--){
            if(chk && s[i] == '0'){
                chk = false;
                cnt1 += i+1;
            }
            else if(!chk && s[i] == '1'){
                chk = true;
                cnt1 += i+1;
            }
        }
        cout<<cnt1<<" "<<cnt<<endl;
        
        long long val = min(cnt1,cnt);
        
        return val;
    }
};