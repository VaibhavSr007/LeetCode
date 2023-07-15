//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp, int n){
        if(i == j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int x=i; x<j; x++){
            int val = arr[i-1] * arr[j] * arr[x] + solve(i, x, arr, dp, n) + solve(x+1, j, arr, dp, n);
            ans = min(ans, val);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));   
        return solve(1, N-1, arr, dp, N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends