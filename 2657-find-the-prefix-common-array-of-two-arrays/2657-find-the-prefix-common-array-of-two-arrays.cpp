class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> a;
        map<int,int> b;
        vector<int> res;
        int ans = 0;
        for(int i=0; i<A.size(); i++){
            a[A[i]]++;
            b[B[i]]++;
            
            if(A[i] == B[i]){
                ans += 1;
            }
            else{
                if(a.find(B[i]) != a.end()){
                ans += a[B[i]];
                }
                if(b.find(A[i]) != b.end()){
                    ans += b[A[i]];
                }
            }
            
            res.push_back(ans);
        }
        return res;
    }
};