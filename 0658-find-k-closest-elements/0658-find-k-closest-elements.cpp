class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        bool chk = false;
        for(auto i:arr){
            if(i == x){
               chk = true;
                break;
            }
        }
        
        vector<int> ans;
        int idx = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        
        if(idx == arr.size()){
            idx = idx-1;
        }
        
        cout<<idx<<" ";
        int i = idx, j=idx+1;
        if(i-1 >=0 && abs(arr[i-1]-x) <= abs(arr[i]-x)){
            j = i;
            i = i-1;
        }
        
        while(true){
            if(i>=0 && j<arr.size()){
                if(abs(arr[i]-x) < abs(arr[j]-x)){
                    ans.push_back(arr[i]);
                    i--;
                }
                else if(abs(arr[i]-x) == abs(arr[j]-x)){
                    ans.push_back(arr[i]);
                    i--;
                }
                else{
                    ans.push_back(arr[j]);
                    j++;
                }
            }
            else if(i>=0 && j>=arr.size()){
                ans.push_back(arr[i]);
                i--;
            }
            else if(i<0 && j < arr.size()){
                ans.push_back(arr[j]);
                j++;
            }
            
            if(ans.size() >= k || (i < 0 && j >= arr.size())){
                break;
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};