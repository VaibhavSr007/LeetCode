//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int solve(int idx, int prev, int arr[], vector<vector<int>> &dp, int n){
	    if(idx == n){
	        return 0;
	    }
	    
	    if(prev != -1 && dp[idx][prev] != -1){
	        return dp[idx][prev];
	    }
	    
	    int ans;
	    if(prev == -1 || arr[idx] > arr[prev]){
	        int pick = arr[idx] + solve(idx+1, idx, arr, dp, n);
	        int npick = solve(idx+1, prev, arr, dp, n);
	        ans = max(pick, npick);
	    }
	    else{
	        ans = solve(idx+1, prev, arr, dp, n);
	    }
	    
	    if(prev != -1){
	        dp[idx][prev] = ans;
	    }
	    return ans;
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	   vector<vector<int>> dp(1000, vector<int>(1000, -1));
	   return solve(0, -1, arr, dp, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends