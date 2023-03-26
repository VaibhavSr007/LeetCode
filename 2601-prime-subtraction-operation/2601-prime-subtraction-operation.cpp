class Solution {
public:
    void SieveOfEratosthenes(int srt, int n, vector<int>& pr){
        bool prime[n + 2 - srt];
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;

        for (int p = srt; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = srt; p <= n; p++)
            if (prime[p])
                pr.push_back(p);
    }
    
    
    int bin(vector<int> v, int target){
        int ans = -1;
        int s = 0;
        int e = v.size()-1;
        while(s<=e){
            int  m = s + (e-s)/2;
            
            if(v[m] <= target){
                ans = v[m];
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return ans;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        
        vector<int> pr;
        int en = *max_element(nums.begin(),nums.end());
        SieveOfEratosthenes(1, en, pr);
        cout<<endl;
        for(int i=0; i<nums.size(); i++){
            int val =0;
            if(i==0){
                 val = nums[i]-1;
            }else{
                val = nums[i]-nums[i-1]-1;
            }
            if(val==0 || val==1){
                continue;
            }
            if(val < 0){
                return false;
            }
            
            int idx = bin(pr, val);
            // cout<<idx<<" ";
            nums[i] -= idx;
            // cout<<nums[i]<<" ";
        }
        
        return true;
    }
};