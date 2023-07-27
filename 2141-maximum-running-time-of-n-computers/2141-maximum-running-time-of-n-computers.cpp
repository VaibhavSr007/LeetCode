class Solution {
public:
    bool check(int n,long long mid,vector<int>&batteries){
        
        long long req = mid*n;
        long long can_make = 0;
        
        for(auto i:batteries){
            can_make+=(min(1ll*i,mid));
        }
        
        return can_make >= req;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long low = 0;
        long long high = 0;
        
        for(auto i:batteries){
            high += i;
        }
        
        
        long long ans = 0;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            
            if(check(n,mid,batteries))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};