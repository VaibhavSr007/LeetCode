class Solution {
public:
    void solve(string num, int idx, int n, vector<string>& v){
        if(idx >= n){
            if(stoll(num) <= INT_MAX && stoll(num) >= INT_MIN)
                v.push_back(num);
            return ;
        }
        
        for(int i=idx; i<n; i++){
            swap(num[idx],num[i]);
            solve(num,idx+1,n,v);
            swap(num[idx],num[i]);
        }
    }
    
    int nextGreaterElement(int n) {
//         if(n==INT_MAX){ return -1;}
//         string num = to_string(n);
//         vector<string> v;
//         vector<long long> ans;
//         solve(num,0,num.length(),v);
                                                       // TLE approach
//         for(auto i:v){
//             ans.push_back(stoll(i));
//         }
        
//         long long res = -1;
//         sort(ans.begin(),ans.end());
        
//         for(auto i:ans){
//             if(i>n){
//                 res = i;
//                 break;
//             }
//         }
        
//         return int(res);
        
        string num = to_string(n);
        int x = -1;
        for(int i=num.length()-2; i>=0; i--){
            if(num[i]<num[i+1]){
                x = i;
                break;
            }
        }
        if(x==-1){
            reverse(num.begin(),num.end());
            int ans = stoll(num);
            if(ans > INT_MAX || ans < INT_MIN){
                return -1;
            }
            else{
                if(ans <= n){
                    return -1;
                }
                else{
                    return ans;
                }
            }
        }
        
        int y=-1;
        for(int i=num.length()-1; i>=0; i--){
            if(num[i]>num[x]){
                y = i;
                break;
            }
        }
        swap(num[x],num[y]);
        reverse(num.begin()+(x+1), num.end());
        int ans = stoll(num);
        if(ans > INT_MAX || ans < INT_MIN){
            return -1;
        }
        else{
            if(ans <= n){
                return -1;
            }
            else{
                return ans;
            }
        }
    }
};