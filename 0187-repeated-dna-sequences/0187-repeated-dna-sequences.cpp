class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string , int> mp;
        string op = "";
        for(int i=0; i<s.size(); i++){
            if(op.size() == 10){
                mp[op]++; 
            }
            op.push_back(s[i]);
            if(op.size() > 10){
                op.erase(op.begin());
            }
            
        }
        if(op.size() == 10){
            mp[op]++; 
        }
        
        for(auto i:mp){
            cout<<i.first<<":"<<i.second<<" ";
            if(i.second > 1){
                ans.push_back(i.first);
            }
        }
        cout<<endl;
        
        return ans;
    }
};