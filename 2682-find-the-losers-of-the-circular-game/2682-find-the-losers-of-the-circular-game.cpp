class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        set<int> s;
        vector<int> ans;
        int val = 0;
        int i = 1;
        while(s.find(val) == s.end()){
            s.insert(val);
            // cout<<val<<" ";
            val = (val + (i*k))%n ;
            i++;
        }
        // cout<<endl;
        for(int i=0; i<n; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};