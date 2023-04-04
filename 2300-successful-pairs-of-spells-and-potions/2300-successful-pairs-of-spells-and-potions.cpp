class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(begin(potions),end(potions));
        vector<int> ans;
        for(int i=0; i<spells.size(); i++){
            long long b = spells[i];
            int s = 0, e = potions.size()-1;
            while(s<=e){
                int m = s + (e-s)/2;
                long long a = potions[m];
                long long x = (a*b);
                if(x < success){
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
            // cout<<potions[s]<<" ";
            int cnt = potions.size()-s;
            ans.push_back(cnt);   
        }
        // cout<<endl;
        return ans;
    }
};