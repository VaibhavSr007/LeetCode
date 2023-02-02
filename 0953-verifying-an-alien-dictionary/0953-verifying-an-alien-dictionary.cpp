class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0; i<order.length(); i++){
            mp[order[i]] = i;
        }
    
        for(int i=0; i<words.size()-1; i++){
            bool flag = false;
            int x=0,y=0;
            while(x<words[i].length() && y<words[i+1].length()){
                if(mp[words[i][x]] > mp[words[i+1][y]]){
                    return false;
                }
                else if(mp[words[i][x]] < mp[words[i+1][y]]){
                    break;
                }
                else if(y==words[i+1].length()-1 && x<words[i].length()-1 
                        && mp[words[i][x]] == mp[words[i+1][y]]){
                    return false;
                }
                x++;
                y++;
            }
        }
        return true;
    }
};